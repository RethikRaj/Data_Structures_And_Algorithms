#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums,int index,vector<int> &subset,vector<vector<int>> &ans){
        // Base Case
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        // 1 case me solve remaining recursion
        // Either include nums[index] in subset or dont
        // Include
        subset.push_back(nums[index]);
        solve(nums,index+1,subset,ans);
        subset.pop_back();

        // exclude
        solve(nums,index+1,subset,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int index = 0;
        solve(nums,index,subset,ans);
        return ans;
    }
};
