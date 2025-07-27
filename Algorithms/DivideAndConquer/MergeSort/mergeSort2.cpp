#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[],int size,int start,int mid,int end){
    int leftLength = mid-start+1;
    int rightLength = end-mid;

    // Create left array and right array
    int *leftArr = new int[leftLength];
    int * rightArr = new int[rightLength];
    // Copy from mainArr to left and right
    int mainArrIndex = start;
    for(int i=0;i< leftLength;i++){
        leftArr[i] = arr[mainArrIndex];
        mainArrIndex++;
    }
    mainArrIndex = mid + 1;
    for(int i=0;i< rightLength;i++){
        rightArr[i] = arr[mainArrIndex];
        mainArrIndex++;
    }

    // Merge left part anf right part
    int i=0;
    int j =0;
    mainArrIndex = start;
    while(i< leftLength && j < rightLength){
        if(leftArr[i] < rightArr[j]){
            arr[mainArrIndex] = leftArr[i];
            i++;
            mainArrIndex++;
        }else{
            arr[mainArrIndex] = rightArr[j];
            j++;
            mainArrIndex++;
        }
    }

    // 2 cases psbl
    while(i < leftLength){
        arr[mainArrIndex] = leftArr[i];
        i++;
        mainArrIndex++;
    }

    while(j < rightLength){
        arr[mainArrIndex] = rightArr[j];
        j++;
        mainArrIndex++;
    }
}

void mergeSort(int arr[],int size,int start,int end){
    // Base case
    // start == end => single element => already sorted => return
    // start > end => invalid array
    if(start >= end){
        return;
    }
    // Divide
    int mid = start + (end-start)/2;
    // Sort(solve) left part
    mergeSort(arr,size,start,mid);
    // Sort(solve) right part
    mergeSort(arr,size,mid+1,end);
    // Conquer
    merge(arr,size,start,mid,end);
}

int main(){
    int arr[] = {10,80,110,90,50,30,40,20};
    int size = 8;
    int s = 0;
    int e = size-1;

    mergeSort(arr,size,s,e);

    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}