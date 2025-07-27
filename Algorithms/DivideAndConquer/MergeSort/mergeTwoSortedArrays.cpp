#include<iostream>
#include<vector>

using namespace std;

void mergeSortedArrays(int arr[],int sizeArr,int brr[],int sizeBrr,vector<int>& ans){
    int i = 0; // i->arr
    int j = 0; // j->brr

    // while i and j are inside its respective bounds
    while(i<sizeArr && j<sizeBrr){
        if(arr[i] < brr[j]){
            ans.push_back(arr[i]);
            i++;
        }else{
            ans.push_back(brr[i]);
            j++;
        }
    }

    // 2 cases psbl here =>
    // 1 case -> arr still has elements
    while(i < sizeArr){
        ans.push_back(arr[i]);
        i++;
    }
    // another case -> brr still has elements
    while(j < sizeBrr){
        ans.push_back(brr[j]);
        j++;
    }
}