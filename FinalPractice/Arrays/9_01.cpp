#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // prefix_sum -> index
        unordered_map<int,int> mp;
        int sum = 0;
        int longest = 0;

        for(int i = 0;i < nums.size(); i++){
            sum += nums[i];

            if(sum == k){
                longest = max(longest, i + 1);
            }

            if(mp.find(sum - k) != mp.end()){
                longest = max(longest, i - mp[sum-k]);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return longest;
    }
};