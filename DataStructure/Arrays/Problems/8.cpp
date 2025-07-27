#include <iostream>
#include <algorithm>
using namespace std;

void sortZeroesAndOnes1(int arr[],int size){
    // step 1: count number of zeroes and ones
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0;i<size;i++){
        if(arr[i] == 0){
            zeroCount++;
        }
        else if(arr[i] == 1){
            oneCount++;
        }
    }

    // step 2 : place zeroCount number of zeroes first and then 1's
    int index = 0;
    while(zeroCount--){
        arr[index] = 0;
        index++;
    }

    while(oneCount--){
        arr[index] = 1;
        index++;
    }

    // step 2 : using fill method
    // fill(arr,arr+zeroCount,0);
    // fill(arr+zeroCount,arr+size,1);
}


// Method 2 : Two Pointer Approach
void sortZeroesAndOnesTwoPointerApproach(int arr[],int size){
    int index = 0;
    int left = 0; // denotes the index in which next zero can come
    while(index < size){
        if(arr[index] == 0){
            swap(arr[index],arr[left]);
            left++;
        }
        index++;
    }
}

void sortZeroesAndOnes3(int arr[],int size){
    sort(arr,arr+size);
}


void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Not needed this : Before learning two pointer i did like this
void sortZeroesAndOnesBruteForce(int arr[],int size){
    int left = 0;
    int right = size-1;
    while(left < right){
        // arr[left] = 0 and arr[right] = 0
        // if(arr[left] == 0 && arr[right] == 0){
        //     left++;
        // }

        // // arr[left] = 0 and arr[right] = 1
        // else if(arr[left] == 0 && arr[right] == 1){
        //     left++;
        //     right--;
        // }

        // // arr[left] = 1 and arr[right] = 0
        // else if(arr[left] == 1 && arr[right] == 0){
        //     swap(arr[left],arr[right]);
        //     left++;
        //     right--;
        // }

        // // arr[left] = 1 and arr[right] = 1
        // else if(arr[left] == 1 && arr[right] == 1){
        //     right--;
        // }




        // simplified conditions :
        
        if(arr[left] == 0){
            left++;
        }
        if(arr[right] == 1){
            right--;
        }
        if(left < right && arr[left] == 1 && arr[right] == 0){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        
    }
}

int main(){
    int arr[] = {0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1}; // zeroes : 10 ,ones : 8
    int n = 18;

    int brr[] = {0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0}; // zeroes : 11 ,ones : 8
    int n2 = 19;

    //sortZeroesAndOnes1(arr,n);
    sortZeroesAndOnesBruteForce(arr,n);
    sortZeroesAndOnesBruteForce(brr,n2);
    //sortZeroesAndOnes3(arr,n);

    sortZeroesAndOnesTwoPointerApproach(arr,n);
    printArray(arr,n);    
    printArray(brr,n2);
}

