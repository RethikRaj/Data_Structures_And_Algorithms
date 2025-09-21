#include <bits/stdc++.h>
using namespace std;

void heapify(int *input, int size, int index) {
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    int smallestIndex = index;

    if (leftIndex < size && input[leftIndex] < input[smallestIndex]) {
        smallestIndex = leftIndex;
    }

    if (rightIndex < size && input[rightIndex] < input[smallestIndex]) {
        smallestIndex = rightIndex;
    }

    if (smallestIndex != index) {
        swap(input[smallestIndex], input[index]);
        heapify(input, size, smallestIndex);
    }
}

// Build Min-Heap (in-place)
void buildHeap(int* input, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(input, size, i);
    }
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    buildHeap(arr, n);

    cout << "Array after buildHeap (Min-Heap): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
