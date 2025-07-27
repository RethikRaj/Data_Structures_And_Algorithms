#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& arr, int target,vector<vector<int>> &answers,vector<int> &ans,int sum,int index){
        // Base case
        if(sum == target){
            answers.push_back(ans);
            return;
        }
        // 1 case me solve remaininig recursion will handle
        for(int i=index;i<arr.size();i++){
            int curr = arr[i];
            // DONT DO THIS MISTAKE : sum += curr;
            int sumPlusCurr = sum + curr;
            // if sum+curr > target => No rec call required for that => Move on to next element
            if(sumPlusCurr > target){
                continue;
            }else{
                // include the curr element
                ans.push_back(curr);
                solve(arr,target,answers,ans,sumPlusCurr,i);
                // backtracking
                ans.pop_back();
            }
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        int index = 0;
        int sum = 0;
        vector<int> ans;
        solve(candidates,target,answers,ans,sum,index);
        return answers;
    }
};


// same logic just coded differently
class Solution2 {
public:
    void solve(vector<int>& arr, int target,vector<vector<int>> &answers,vector<int> &ans,int sum,int index){
        // Base case
        if(sum > target){
            return;
        }
        if(sum == target){
            answers.push_back(ans);
            return;
        }
        // 1 case me solve remaininig recursion will handle
        for(int i=index;i<arr.size();i++){
            // include the curr element
            ans.push_back(arr[i]);
            solve(arr,target,answers,ans,sum+arr[i],i);
            // backtracking
            ans.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        int index = 0;
        int sum = 0;
        vector<int> ans;
        solve(candidates,target,answers,ans,sum,index);
        return answers;
    }
};

// other coding ideas

// instead of taking sum = 0 , start from sum = target ,then decrease ... if reached 0 => base case, if reached < 0 one morebase case.