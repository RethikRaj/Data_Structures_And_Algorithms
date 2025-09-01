//  find largest element

#include <bits/stdc++.h>
using namespace std;

int findLargest(vector<int> &arr){
    int ans = INT_MIN;
    for(int i=0;i<arr.size();i++){
        ans = max(ans,arr[i]);
    }
    return ans;
}