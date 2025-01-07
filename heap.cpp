#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;      // Array to store heap elements
    int size;       // Current number of elements in the heap
    int capacity;   // Maximum capacity of the heap

    // Function to maintain heap property (min-heap)
    void heapify(int index) {
        int smallest = index;            // Assume the smallest element is at index
        int left = 2 * index + 1;        // Left child index
        int right = 2 * index + 2;       // Right child index

        // If left child exists and is smaller than the current smallest
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // If right child exists and is smaller than the current smallest
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If the smallest element is not the current index, swap them
        if (smallest != index) {
            swap(heap[index], heap[smallest]);  // Swap the elements
            heapify(smallest);  // Recursively heapify the affected subtree
        }
    }

public:
    // Constructor to initialize the heap with a given capacity
    MinHeap(int cap) : capacity(cap), size(0) {
        heap = new int[cap];  // Allocate memory for the heap array
    }

    // Insert a new value into the heap
    void insert(int value) {
        if (size >= capacity) {  // Check if heap is full
            cout << "Heap is full!" << endl;
            return;
        }

        // Insert the new element at the end of the heap
        heap[size] = value;
        int current = size++;  // Increment size and store the current index

        // Bubble up the newly inserted element to restore heap property
        while (current > 0 && heap[(current - 1) / 2] > heap[current]) {
            swap(heap[(current - 1) / 2], heap[current]);  // Swap with parent
            current = (current - 1) / 2;  // Move to the parent's index
        }
    }

    // Extract the minimum element (root of the heap)
    int extractMin() {
        if (size <= 0) {  // If the heap is empty
            cout << "Heap is empty!" << endl;
            return -1;
        }

        if (size == 1) {  // If there is only one element, return it
            size--;
            return heap[0];
        }

        // Store the root (minimum value)
        int root = heap[0];
        // Replace root with the last element
        heap[0] = heap[--size];
        // Restore the heap property by heapifying the root
        heapify(0);

        return root;  // Return the extracted minimum value
    }

    // Display the elements of the heap
    void display() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";  // Print each element
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap(10);  // Create a min-heap with a capacity of 10

    // Insert elements into the heap
    heap.insert(3);
    heap.insert(2);
    heap.insert(1);
    heap.insert(7);

    // Display the heap elements
    heap.display();  // Output: 1 2 3 7

    // Extract the minimum element (root) from the heap
    cout << "Extracted min: " << heap.extractMin() << endl;  // Output: Extracted min: 1

    // Display the heap after extraction
    heap.display();  // Output: 2 7 3

    return 0;
}
