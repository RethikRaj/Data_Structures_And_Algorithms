#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(int n){
        // base case
        if(n <= 1){
            return 1;
        }
        // 1 case me solve remaining recursion will solve
        int oneStep = solveUsingRecursion(n-1);
        int twoStep = solveUsingRecursion(n-2);
        return oneStep + twoStep;
    }

    int solveUsingMemoization(int n,vector<int> &dp){
        // base case
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        // 1 case me solve remaining recursion will solve
        int oneStep = solveUsingMemoization(n-1,dp);
        int twoStep = solveUsingMemoization(n-2,dp);
        dp[n] = oneStep + twoStep;
        return dp[n];
    }

    int solveUsingTabulation(int n){
        // step 1 : 
        vector<int> dp(n+1,-1);

        //  step 2:
        dp[1] = 1;
        dp[0] = 1;

        // step 3: n : n to 0 => reverse it and  copy paste logic
        for(int i = 2 ; i<=n;i++){
            int oneStep = dp[i-1];
            int twoStep = dp[i-2];
            dp[i] = oneStep + twoStep;
        }

        return dp[n];
    }

    int solveUsingTabulationSpaceOptimisation(int n){
        int prev1 = 1;
        int prev2 = 1;

        for(int i = 2 ; i<=n;i++){
            int oneStep = prev1;
            int twoStep = prev2;
            int curr = oneStep + twoStep;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }


    int climbStairs(int n) {
        //return solveUsingRecursion(n);

        // step 1 : n : n to 0 => size : n+1
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(n,dp);

        //return solveUsingTabulation(n);

        return solveUsingTabulationSpaceOptimisation(n);
    }
};
