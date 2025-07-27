#include <iostream>
#include <limits.h>
using namespace std;



int secondLargest1(int arr[],int size){
    int firstMax = INT_MIN;
    for(int i=0;i<size;i++){
        firstMax = max(firstMax,arr[i]);
    }
    
    int secondMax = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i] != firstMax){
            secondMax = max(secondMax,arr[i]);
        }
    }
    
    if(secondMax != INT_MIN){
        return secondMax;
    }else{
        return -1;
    }
}

int secondLargest2(int arr[],int size){
    int firstMax = INT_MIN;
    int secondMax;

    for(int i=0;i<size;i++){
        if(arr[i] > firstMax){
            secondMax = firstMax;
            firstMax = arr[i];
        }else if(arr[i] > secondMax && arr[i] != firstMax){ // eg : 8,8,7,6,5
            secondMax = arr[i];
        }
    }

    return secondMax;
}

int secondSmallest(int arr[],int size){
    int firstMin = INT_MAX;
    int secondMin = INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i] < firstMin){
            secondMin = firstMin;
            firstMin = arr[i];
        }else if(arr[i] < secondMin && arr[i] != firstMin){
            secondMin = arr[i];
        }
    }
    
    return secondMin;
}

int main(){
    int arr[] = {10,5,1,12,10,12,1};
    int n = 7;
    

    cout << "The second largest element is : " << secondLargest2(arr,n) << endl;
}