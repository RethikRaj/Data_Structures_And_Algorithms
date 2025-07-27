#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[],int size,int start,int mid,int end){
    int i = start; // i denotes left part i.e., from start to mid
    int j = mid+1; // j denotes right part i.e., from mid+1 to end
    vector<int> ans;

    while(i<= mid && j <= end){
        if(arr[i] < arr[j]){
            ans.push_back(arr[i]);
            i++;
        }else{
            ans.push_back(arr[j]);
            j++;
        }
    }

    // 2 cases psbl
    // 1 case => elements still in left part
    while(i <= mid){
        ans.push_back(arr[i]);
        i++;
    }
    // Another case => elements still in right part
    while(j <= end){
        ans.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    int mainArrIndex = start;
    for(int i=0;i<ans.size();i++){
        arr[mainArrIndex] = ans[i];
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