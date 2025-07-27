#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
    public:
        int* arr;
        int capacity;// total number of elements that heap can hold;
        int size; // current number of elements;

        MaxHeap(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            size = 0;
        }

        void insert(int val){
            if(size == capacity-1){
                // overflow
                cout << " OVERFLOW " << endl;
                return;
            }

            // step 1 : insert at the first empty position
            // step 2 : then compare the element with its parent and put 

            size++;
            int index = size;
            arr[index] = val;
            while(index > 1 && arr[index] > arr[index/2]){
                swap(arr[index],arr[index/2]);
                index = index/2;
            }
        }

        int deleteFromHeap(){
            if(size == 0){
                cout << "UNDERFLOW" << endl;
                return INT_MIN;
            }

            int ans = arr[1];
            // replace
            swap(arr[1],arr[size]);
            // remove
            size--;
            // heapify root node
            int index = 1;
            while(index <= size){
                int left = 2*index;
                int right = 2*index+1;
                // find largest Index
                int largestIndex = index;
                if(left <= size && arr[largestIndex] < arr[left]){
                    largestIndex = left;
                }
                if(right <= size && arr[largestIndex] < arr[right]){
                    largestIndex = right;
                }

                // swap if index != largestIndex else break
                if(largestIndex == index){
                    break;
                }else{
                    swap(arr[index],arr[largestIndex]);
                    // IMP STEP
                    index = largestIndex;
                }
            }
            return ans;
        }

        void printHeap(){
            for(int i=1;i<=size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    MaxHeap* hp = new MaxHeap(10);

    vector<int> input = {50,10,20,40,55,60,45,30,5,7};

    for(int i=0;i<input.size();i++){
        hp->insert(input[i]);
        hp->printHeap();
    }

    // Deleetion
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();
    cout << "Deleted : " << hp->deleteFromHeap() << endl;
    hp->printHeap();

    return 0;
}