#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Method 2 : Using set but here set<vector<int>> is giving a headache as it requires a separate hash function

// Method 1 : Using map to solve duplicacy
void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> permutation,unordered_map<int,int> &mapping){
    if(permutation.size() == nums.size()){
        ans.push_back(permutation);
        return;
    }

    unordered_map<int,int>::iterator it = mapping.begin();
    while(it != mapping.end()){
        int key = (*it).first;
        if(mapping[key] != 0){
            mapping[key] -= 1;
            permutation.push_back(key);
            solve(nums,ans,permutation,mapping);
            permutation.pop_back();
            mapping[key] += 1;
        }
        // Dont forgget
        it++;
    }
    
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int,int> mapping;
    for(int i=0;i<nums.size();i++){
        mapping[nums[i]] += 1;
    }

    vector<vector<int>> ans;
    vector<int> permutation;
    solve(nums,ans,permutation,mapping);

    return ans;
}

