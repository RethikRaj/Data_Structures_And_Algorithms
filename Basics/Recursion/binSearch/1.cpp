#include<iostream>
#include<vector>
using namespace std;

int binSearchRecursive(int arr[],int size,int s,int e,int target){
    if(s>e){
        return -1;
    }
    int mid = s + (e-s)/2;
    // 1 case me
    if(arr[mid] == target){
        return mid;
    }
    // remaining recursive
    if(target > arr[mid]){
        // right
        binSearchRecursive(arr,size,mid+1,e,target);
    }
    else{
        // left
        binSearchRecursive(arr,size,s,mid-1,target);
    }

}