#include<iostream>
using namespace std;

void printArr(int arr[],int size,int index){
    if(size == index){
        return;
    }
    // 1case
    cout << arr[index] << " ";
    // Remaining
    printArr(arr,size,index+1);
}

bool searchInArr(int arr[],int size,int index,int target){
    if(size == index){
        return false;
    }
    // 1case
    if(arr[index] == target){
        return true;
    }
    // Remaining
    return searchInArr(arr,size,index+1,target);
}