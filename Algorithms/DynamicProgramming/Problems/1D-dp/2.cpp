#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<int> &arr,int index){
        // base case
        if(index >= arr.size()){
            return 0;
        }

        // 1 case me solve remaining recursion will handle
        int include = arr[index] + solveUsingRecursion(arr,index+2);
        int exclude = 0 + solveUsingRecursion(arr,index+1);
        int ans = max(include,exclude);
        return ans;
    }

    int solveUsingMemoization(vector<int> &arr,int index,vector<int> &dp){
        // base case
        if(index >= arr.size()){
            return 0;
        }
        // step 3 : check whether already exists -> if exist then return
        if(dp[index] != -1){
            return dp[index];
        }

        // 1 case me solve remaining recursion will handle
        int include = arr[index] + solveUsingMemoization(arr,index+2,dp);
        int exclude = 0 + solveUsingMemoization(arr,index+1,dp);
        // step 2 : store recAns and return from dp
        dp[index]= max(include,exclude);
        return dp[index];
    }

    int solveUsingTabulation(vector<int> &arr){
        int n = arr.size();
        // step 1 : since only one parameter changes -> 1D dp
        // index goes from 0 to n -> size of dp array is (n+1)
        vector<int> dp(n+2,-1); // i took n+2 so that we dont get index out of bounds during 1st iteration of loop

        // step 2 : Analyse base cases and update dp array
        dp[n+1] = 0;
        dp[n] = 0;

        // step 3 :parameter range of memoization is 0 to n -> Tabulation : n -> 0 but since dp[n] is already calculater => n-1 to 0
        for(int i = n-1;i >= 0;i--){
            int include = arr[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i]= max(include,exclude);
        }
        return dp[0];
    }

    int solveUsingTabulationSpaceOptimised(vector<int> &arr){
        int n = arr.size();
        int next2 = 0;
        int next1 = 0;

        for(int i=n-1;i>=0;i--){
            int include = arr[i] + next2;
            int exclude = 0 + next1;
            int curr = max(include,exclude);
            // DONT FORGET
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        // normal recursion
        // int index = 0;
        // return solveUsingRecursion(nums,index); 

        // memoization
        // step 1 : since only one parameter changes -> 1D dp
        // index goes from 0 to n -> size of dp array is (n+1)
        // int index = 0;
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(nums,index,dp);

        // tabulation
        // return solveUsingTabulation(nums);

        // space optimised
        return solveUsingTabulationSpaceOptimised(nums);

    }
};
