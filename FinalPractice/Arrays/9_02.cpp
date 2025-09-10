#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sum -> how much times that sum has occured
        unordered_map<int,int> mp;
        int sum = 0;
        int totalSubarray = 0;

        for(int i = 0;i < nums.size(); i++){
            sum += nums[i];

            if(sum == k){
                totalSubarray += 1;
            }

            if(mp.find(sum - k) != mp.end()){
                totalSubarray += mp[sum-k];
            }
            // Store frequency of currentSum
            mp[sum] += 1;
        }

        return totalSubarray;
    }
};