#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    set<int> ans_set;
    
    int i=0;
    int j=0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            ans_set.insert(arr1[i]);
            i++;
        }else{
            ans_set.insert(arr2[j]);
            j++;
        }
    }
    
    // j is exhausted
    while(i < n){
        ans_set.insert(arr1[i]);
        i++;
    }
    
    // i is exhausted
    while(j < m){
        ans_set.insert(arr2[j]);
        j++;
    }
    
    vector<int> ans(ans_set.begin(),ans_set.end());
    return ans;
}

