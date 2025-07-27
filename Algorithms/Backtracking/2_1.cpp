#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> permutation,vector<int> &visited){
    if(permutation.size() == nums.size()){
        ans.push_back(permutation);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(visited[i] == false){
            visited[i] = true;
            permutation.push_back(nums[i]);
            solve(nums,ans,permutation,visited);
            // backtracking 
            permutation.pop_back(); // Important
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> permutation;
    vector<int> visited(nums.size(),false);
    solve(nums,ans,permutation,visited);
    return ans;
}



// Method 2 : swap method

void solve(vector<int>& nums,vector<vector<int>> &ans,int i){
    if(i >= nums.size()){
        ans.push_back(nums);
        return;
    }
    // 1 case me solve remainining recursion
    // give opportunity for each charcter to be placed in iTh index
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,ans,i+1);
        // Backtracking
        swap(nums[i],nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int i = 0;
    solve(nums,ans,i);
    return ans;
}


