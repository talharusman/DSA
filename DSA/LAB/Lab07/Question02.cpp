#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int finishTime;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner* leftArr = new Runner[n1];
    Runner* rightArr = new Runner[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].finishTime <= rightArr[j].finishTime) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int numParticipants = 10;
    Runner runners[numParticipants];
    cout << "Enter the names and finish times (in seconds) of the participants:\n";
    for (int i = 0; i < numParticipants; i++) {
        cout << "Participant " << i + 1 << " Name: ";
        cin >> runners[i].name;
        cout << "Finish Time (seconds): ";
        cin >> runners[i].finishTime;
    }
    mergeSort(runners, 0, numParticipants - 1);
    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].finishTime << " seconds\n";
    }

    return 0;
}
