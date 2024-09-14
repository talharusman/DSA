#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(int arr[]){
	int temp = 0;
	int size = 5;
	bool check;
	for(int i = 0; i < size - 1; i++){
		check = false;
		for(int j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				check = true;
			}
		}
		if(!check){
			break;
		}	
	}
}

void selectionSort(int arr[]){
	int temp = 0;
	int size = 5;
	
	for(int i = 0; i < size - 1; i++){
		int minIndex = i;
		for(int j = i+1; j < size - 1; j++){
			if(arr[minIndex] > arr[j+1]){
				minIndex = j;
			}
		}
		if(minIndex != i){
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

void insertionSort(int arr[]){
	int size = 5;
	
	for(int i = 1; i < size-1; i++){
		int key = arr[i];
		int j = i-1;
		for(; j >= 0 && arr[j] > key; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void shellSort(int arr[]){
	int n = 5;
	
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			int temp = arr[i];
			int j = i;
			for(; j >= gap && arr[j-gap]; j -= gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int GNP(int gap)
{
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

void combSort(int a[], int n)
{
    int gap = n;

    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = GNP(gap);

        swapped = false;

        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

int linearSearch(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// BINARY SEARCH
void sortedArray(int arr[], int size)
{
    int temp = 0;
    bool check;
    for (int i = 0; i < size - 1; i++)
    {
        check = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check = true;
            }
        }
        if (!check)
        {
            break;
        }
    }
}

bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

int binarySearch(int arr[], int target, int size)
{
    if (!isSorted(arr, size))
    {
        sortedArray(arr, size);
    }

    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int key, int size)
{
    if (!isSorted(arr, size))
    {
        sortedArray(arr, size);
    }

    int pos = 0, low = 0, high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {

        if (low == high)
        {
            if (arr[low] == key)
            {
                return low;
            }
            return -1;
        }

        pos = low + (((key - arr[low]) * (high - low)) / (arr[high] - arr[low]));

        if (arr[pos] == key)
        {
            return pos;
        }

        if (arr[pos] < key)
        {
            low = pos + 1;
        }

        else
        {
            high = pos - 1;
        }
    }

    return -1;
}

int main(){
	int arr[] = {5,4,3,2,1};
	
	bubbleSort(arr);
	
	cout<<"BUBBLE SORT: "<<endl;
	for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
	
	cout<<"SELECTION SORT: "<<endl;
	selectionSort(arr);
	for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<",";
	}
	
	cout<<endl;
	cout<<"INSERTION SORT: "<<endl;
	insertionSort(arr);
	for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<",";
	}
	
	cout<<endl;
	cout<<"SHELL SORT: "<<endl;
	shellSort(arr);
	for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
	cout<<"COMB SORT: "<<endl;
	combSort(arr,5);
	for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i]<<",";
	}
	cout << endl;
    	cout << "LINEAR SEARCH: ";
    	int a = linearSearch(arr, 4, 5);
    	cout << a;
	
    	cout << endl;
    	cout << "BINARY SEARCH: ";
    	int b = binarySearch(arr, 4, 5);
    	cout << b;

    	cout << endl;
    	cout << "INTERPOLATION SEARCH: ";
    	int c = interpolationSearch(arr, 5, 5);
    	cout << c;
}