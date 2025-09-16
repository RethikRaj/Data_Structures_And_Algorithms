#include <iostream>
#include <vector>
using namespace std;

// 0-based
class MaxHeap{
    private:
        int* heap;      // array to store heap elements
        int capacity;   // maximum possible size of heap
        int size;       // current number of elements in heap

        // swap two elements
        void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
        
        // Move element up
        void heapifyUp(int i) {
            while (i > 0) {  // i = 0 => root => root has no parent => Stop
                int parentIndex = (i - 1) / 2;
                if (heap[i] > heap[parentIndex]) {
                    swap(heap[i], heap[parentIndex]);
                    i = parentIndex;  // keep moving up
                } else {
                    break;  // heap property satisfied
                }
            }
        }

        // !Move element down => Note : HeapifyDown is same as heapify 
        void heapifyDown(int index){
            int leftIndex = 2*index + 1;
            int rightIndex = 2*index + 2;

            int largestIndex = index;

            if(leftIndex < size && heap[leftIndex] > heap[largestIndex]){
                largestIndex = leftIndex;
            }

            if(rightIndex < size && heap[rightIndex] > heap[largestIndex]){
                largestIndex = rightIndex;
            }

            if(largestIndex != index){
                swap(heap[largestIndex], heap[index]);
                heapifyDown(largestIndex);
            }
            
        }


    public:
        MaxHeap(int capacity){
            this->capacity = capacity;
            this->heap = new int[capacity];
            this->size = 0;
        }

        ~MaxHeap() {
            delete[] heap;
        }

        void insert(int val){
            if(size == capacity){
                cout << "Heap is full. Cannot insert " << val << "\n";
                return;
            }

            heap[size] = val;
            heapifyUp(size);
            size++;
        }

        // Remove and return max
        int extractMax(){
            if(size == 0){
                cout << "Heap is empty!\n";
                return INT_MIN;
            }

            int max = heap[0];
            swap(heap[0], heap[size-1]);
            size--;
            // Only if after deleting atleast one element present present then call heapifyDown
            if (size > 0) {
                heapifyDown(0);
            }
            return max;
        }

        int getMax() {
            return (size > 0) ? heap[0] : INT_MIN;
        }

        void display(){
            for(int i = 0; i < size;i++){
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};


int main() {
    MaxHeap h(5); // heap with capacity 5

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    cout << "Heap elements: ";
    h.display();

    cout << "Max element: " << h.getMax() << "\n";

    cout << "Extracted: " << h.extractMax() << "\n";

    cout << "Heap after extraction: ";
    h.display();

    h.insert(50); // should work
    h.display();
    h.insert(60); // should print "Heap is full!"

    return 0;
}