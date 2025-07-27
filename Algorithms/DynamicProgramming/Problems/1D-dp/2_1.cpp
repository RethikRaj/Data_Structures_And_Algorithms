#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<int> &nums,int start,int end){
        // base case
        if(start > end){
            return 0;
        }
        // 1 case me solve remaining recursion will solve
        int include = nums[start] + solveUsingRecursion(nums,start+2,end);
        int exclude = 0 + solveUsingRecursion(nums,start+1,end);
        int ans = max(include,exclude);
        return ans;
    }

    int solveUsingMemoization(vector<int> &nums,int start,int end,vector<int> &dp){
        // base case
        if(start > end){
            return 0;
        }

        // step 3 : 
        if(dp[start] != -1){
            return dp[start];
        }

        // 1 case me solve remaining recursion will solve
        int include = nums[start] + solveUsingMemoization(nums,start+2,end,dp);
        int exclude = 0 + solveUsingMemoization(nums,start+1,end,dp);
        // step 2 : store and return from dp array
        dp[start] = max(include,exclude);
        return dp[start];
    }

    int solveUsingTabulation(vector<int> &nums,int start,int end){
        int n = nums.size();
        // step 1 : create a dp array
        vector<int> dp(n+2,-1);

        // step 2 : update the dp array by analysing base cases
        for(int i=end+1;i < n+2;i++){
            dp[i] = 0;
        }

        // step 3 : start : start to end => reverse it and copy paste logic
        for(int i = end ; i >= start; i--){
            int include = nums[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include,exclude);
        }

        return dp[start];
    }

    int solveUsingTabulationSpaceOptimisation(vector<int> &nums,int start,int end){
        int n = nums.size();
        int next2 = 0;
        int next1 = 0;

        for(int i=end;i>=start;i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            int curr = max(include,exclude);
            // shifting => IMPPPPPP
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        // solve using recursion
        // int firstHouseInclude = nums[0] + solveUsingRecursion(nums,2,n-2);
        // int firstHouseExclude = 0 + solveUsingRecursion(nums,1,n-1);
        // return max(firstHouseInclude,firstHouseExclude);

        // solve using memoization
        // step 1 : create a 1D dp => start :(0 to n+1)
        // vector<int> dp(n+2,-1);
        // int firstHouseInclude = nums[0] + solveUsingMemoization(nums,2,n-2,dp);
        // // Reinitialise dp again => IMPPPP
        // dp = vector<int>(n+2,-1);
        // int firstHouseExclude = 0 + solveUsingMemoization(nums,1,n-1,dp);
        // return max(firstHouseInclude,firstHouseExclude);

        // solve using tabulation
        // int firstHouseInclude = nums[0] + solveUsingTabulation(nums,2,n-2);
        // int firstHouseExclude = 0 + solveUsingTabulation(nums,1,n-1);
        // return max(firstHouseInclude,firstHouseExclude);

        // space optimisation
        int firstHouseInclude = nums[0] + solveUsingTabulationSpaceOptimisation(nums,2,n-2);
        int firstHouseExclude = 0 + solveUsingTabulationSpaceOptimisation(nums,1,n-1);
        return max(firstHouseInclude,firstHouseExclude);

    }
};