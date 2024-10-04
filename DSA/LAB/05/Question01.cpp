#include<iostream>
using namespace std;

void Sort(int arr[], int size,int i, int j){
    int temp;
    if(i >= size-1){
        return;
    }
    if(j == size){
        i += 1;
        j = i;
    }
    if(arr[i] > arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    Sort(arr,size,i,j+1);
    
}

int main(){
    int arr[] = {45,25,45,85,14,85,96,2,5,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    Sort(arr,size,0,0);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
