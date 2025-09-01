// find minimum element

#include <bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &arr){
    int ans = INT_MAX;
    for(int i=0;i<arr.size();i++){
        ans = min(ans,arr[i]);
    }
    return ans;
}