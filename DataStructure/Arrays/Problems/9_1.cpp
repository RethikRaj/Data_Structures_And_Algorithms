#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Right Rotate by K:

// Method 1 : store last k elements in temp then shift then copy back

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k%n;
        // Store last k elements in array
        vector<int> temp(k);
        for(int i=n-k;i<n;i++){
            temp[i-(n-k)] = arr[i];
        }
        // rotate ->Shift
        for(int i=n-1;i>=k;i--){
            arr[i] = arr[i-k];
        }
        // Copy
        for(int i=0;i<k;i++){
            arr[i] = temp[i];
        }
    }
};


// Method2 : Right shift by one k times

void rightShiftByOne(int arr[],int size){
    // Step 1
    int temp = arr[size-1];

    // Step 2 => shift -> arr[i] = arr[i-1]
    for(int i=size-1;i>=1;i--){
        arr[i] = arr[i-1];
    }
    // Copy temp to 0th index
    arr[0] = temp;
}

void rightShiftByKMethod2(int arr[],int size, int k) {
    for(int i=0;i<k;i++){
        rightShiftByOne(arr,size);
    }
}


// Method 3: circular counting =>modulus operator

void rotate(vector<int>& arr, int k) {
    int size = arr.size();
    vector<int> temp(size);

    for(int i=0;i<size;i++){
        int newIndex = (i+k)%size;
        temp[newIndex] = arr[i];
    }

    arr = temp;
}

// method 4: Reversing method
// way 1
void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k%n;
    // reverse whole array
    reverse(arr.begin(),arr.end());
    // reverse first k elements
    reverse(arr.begin(),arr.begin()+k);
    // reverse last n-k elements
    reverse(arr.begin()+k,arr.end());
}

// way 2
void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k%n;
    // reverse first n-k elements
    reverse(arr.begin(),arr.begin()+n-k);
    // reverse last k elements
    reverse(arr.begin()+n-k,arr.end());
    // reverse whole array
    reverse(arr.begin(),arr.end());
}



// Left Rotate BY K

// Method1 :



// METHOD 2 : LEft rotate by 1 k times.
void leftRotateByOne(int arr[],int size){
    int temp = arr[0];
    for(int i=0;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}

void leftRotateByk(int arr[],int size,int k){
    for(int i=0;i<k;i++){
        leftRotateByOne(arr,size);
    }
}



int main(){
    int arr[] = {10,20,30,40,50,60,70};
    int n = 7;

    //rightShiftBy2places(arr,n);

    int k = 3;
    rightShiftByK(arr,n,k);
    printArray(arr,n);
    
}