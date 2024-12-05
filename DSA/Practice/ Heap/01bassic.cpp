#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heapArray; // Vector to store the heap

    // Function to heapify a subtree rooted at index i (max-heap)
    void heapifyDown(int i) {
        int largest = i;             // Initialize largest as root
        int left = 2 * i + 1;        // Left child
        int right = 2 * i + 2;       // Right child

        // Check if left child exists and is greater than root
        if (left < heapArray.size() && heapArray[left] > heapArray[largest])
            largest = left;

        // Check if right child exists and is greater than largest so far
        if (right < heapArray.size() && heapArray[right] > heapArray[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            heapifyDown(largest); // Recursively heapify the affected subtree
        }
    }

    // Function to heapify up (used after insertion)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        // If current node is greater than its parent, swap and recurse
        if (i > 0 && heapArray[i] > heapArray[parent]) {
            swap(heapArray[i], heapArray[parent]);
            heapifyUp(parent); // Recursively heapify up
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value) {
        heapArray.push_back(value);      // Add the value to the end
        heapifyUp(heapArray.size() - 1); // Fix the heap property upwards
    }

    // Remove the maximum element (root of the heap)
    void deleteMax() {
        if (heapArray.empty()) {
            cout << "Heap is empty. Cannot delete.\n";
            return;
        }

        // Replace root with last element and remove the last element
        heapArray[0] = heapArray.back();
        heapArray.pop_back();

        // Fix the heap property downwards
        heapifyDown(0);
    }

    // Get the maximum value (root of the heap)
    int getMax() {
        if (heapArray.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return heapArray[0];
    }

    // Display the heap
    void display() {
        cout << "Heap: ";
        for (int val : heapArray) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Main Function
int main() {
    Heap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);

    cout << "Heap after insertions:\n";
    heap.display();

    cout << "\nMaximum value: " << heap.getMax() << endl;

    heap.deleteMax();
    cout << "\nHeap after deleting the maximum value:\n";
    heap.display();

    heap.deleteMax();
    cout << "\nHeap after deleting the maximum value again:\n";
    heap.display();

    return 0;
}
