#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(int n){
        // base case
        if(n==0 || n==1){
            return n;
        }
        // 1 case me solve remaining recursion will solve
        int recAns = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);
        return recAns;
    }

    int solveUsingMemoization(int n,vector<int>& dp){
        // base case
        if(n == 0 || n == 1){
            return n;
        }
        // step3 : if ans already exists then return it
        if(dp[n] != -1){
            return dp[n];
        }

        // step2 : store recAns in dp & return
        dp[n] = solveUsingMemoization(n-1,dp) + solveUsingMemoization(n-2,dp);
        return dp[n];
    }

    int solveUsingTabulation(int n){
        // step1 : Create dp array
        vector<int> dp(n+1,-1);

        // step 2 : analyse base case and copy paste base case and update dp 
        if(n == 0 || n == 1){
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;

        // step 3 : check parameter range and reverse it and run a loop
        // recursive approach : n --> 0
        // bottom up approach : 0--->n
        for(int i=2;i<=n;i++){
            // copy - paste logic -> dp[n] = solveUsingMemoization(n-1,dp) + solveUsingMemoization(n-2,dp);
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int solveUsingTabulationSpaceOptimised(int n){
        if(n == 0 || n == 1){
            return n;
        }
        //dp[0] = 0;
        int prev2 = 0;
        //dp[1] = 1;
        int prev1 = 1;
        for(int i=2;i<=n;i++){
            int ans = prev2 + prev1;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    int fib(int n) {
        // Normal recursion
        //return solveUsingRecursion(n);


        // memoization
        // step 1 : 1D dp -> because only n parameter changes during each rec call
        // what is the size of 1D dp arrray ? -> shld store from 0 to n -> size : n+1
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(n,dp);


        //return solveUsingTabulation(n);

        return solveUsingTabulationSpaceOptimised(n);
    }
};