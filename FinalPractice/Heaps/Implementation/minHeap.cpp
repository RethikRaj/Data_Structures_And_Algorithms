#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    private:
        int *heap;
        int capacity;
        int size;

        void heapifyUp(int index){
            while(index > 0){
                int parentIndex = (index-1)/2;

                if(heap[parentIndex] > heap[index]){
                    swap(heap[parentIndex], heap[index]);
                    index = parentIndex;
                }else{
                    break;
                }
            }
        }

        void heapifyDown(int index){
            int leftIndex = 2*index + 1;
            int rightIndex = 2*index + 2;

            int smallestIndex = index;

            if(leftIndex < size && heap[leftIndex] < heap[smallestIndex]){
                smallestIndex = leftIndex;
            }

            if(rightIndex < size && heap[rightIndex] < heap[smallestIndex]){
                smallestIndex = rightIndex;
            }

            if(smallestIndex != index){
                swap(heap[smallestIndex], heap[index]);
                heapifyDown(smallestIndex);
            }
        }


    public:
        MinHeap(int capacity){
            this->capacity = capacity;
            this->heap = new int[capacity];
            this->size = 0;
        }

        ~MinHeap(){
            delete[] heap;
        }

        void insert(int val){
            if(size == capacity){
                cout << "Heap is full. Cannot insert " << val << "\n";
                return;
            }
            heap[size] = val;
            heapifyUp(size);
            size += 1;
        }
        
        int extractMin(){
            if(size == 0){
                cout << "Heap is empty!\n";
                return INT_MAX;
            }
            int min = heap[0];
            swap(heap[size-1], heap[0]);
            size--;
            if(size > 0){
                heapifyDown(0);
            }
            return min;
        }

        int getMin() {
            return (size > 0) ? heap[0] : INT_MAX;
        }

        void display(){
            for(int i = 0; i < size;i++){
                cout << heap[i] << " ";
            }
            cout << endl;
        }

};

int main() {
    MinHeap h(5); // heap with capacity 5

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    cout << "Heap elements: ";
    h.display();

    cout << "Min element: " << h.getMin() << "\n";

    cout << "Extracted: " << h.extractMin() << "\n";

    cout << "Heap after extraction: ";
    h.display();

    h.insert(50); // should work
    h.display();
    h.insert(60); // should print "Heap is full!"

    return 0;
}