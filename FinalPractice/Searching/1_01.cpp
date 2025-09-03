// Linear search => Reduces the search space linearly

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}