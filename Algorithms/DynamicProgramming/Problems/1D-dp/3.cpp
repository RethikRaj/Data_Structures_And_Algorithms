#include <iostream>
#include <vector>

using namespace std;

// method 1 :
// Uses 1D dp -> Best
class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int remAmount){
        // base case
        if(remAmount == 0){
            return 0;
        }

        // 1 case me solve remaining recursion will handle
        int minCoins = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int currCoin = coins[i];
            if(remAmount >= currCoin){
                int recAns = solveUsingRecursion(coins,remAmount-currCoin);
                if(recAns != INT_MAX)
                    minCoins = min(minCoins,1+recAns);
            }
        }
        return minCoins;
    }

    int solveUsingMemoization(vector<int>& coins, int remAmount,vector<int> &dp){
        // base case
        if(remAmount == 0){
            return 0;
        }

        // step 3 :
        if(dp[remAmount] != -1){
            return dp[remAmount];
        }

        // 1 case me solve remaining recursion will handle
        int minCoins = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int currCoin = coins[i];
            if(remAmount >= currCoin){
                int recAns = solveUsingMemoization(coins,remAmount-currCoin,dp);
                if(recAns != INT_MAX)
                    minCoins = min(minCoins,1+recAns);
            }
        }
        // step 2 : store and return from dp array
        dp[remAmount] = minCoins;
        return dp[remAmount];
    }

    int solveUsingTabulation(vector<int> &coins,int amount){
        // step 1 : Create a 1D dp since only 1 parameter changes
        // remAmount goes from amount to 0 => size : amount+1
        vector<int> dp(amount+1,-1);

        // step 2 : analyse base cases and update dp array
        dp[0] = 0;

        // step 3 : parameter range in recursion -> remAmount : amount to 0 => reverse it and copy paste logic
        // amt : 0 to amount but since 0 is already updated in step 2 => amt : 1 to amount
        for(int amt = 1;amt <= amount;amt++){
            int minCoins = INT_MAX;
            for(int i=0;i<coins.size();i++){
                int currCoin = coins[i];
                if(amt >= currCoin){
                    int recAns = dp[amt-currCoin];
                    if(recAns != INT_MAX)
                        minCoins = min(minCoins,1+recAns);
                }
            }
            dp[amt] = minCoins;
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Normal Recursion
        // int remAmount = amount;
        // int ans = solveUsingRecursion(coins,remAmount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;

        // top-down approach
        // int remAmount = amount;
        // // step 1 : Create a 1D dp since only 1 parameter changes
        // // remAmount goes from amount to 0 => size : amount+1
        // vector<int> dp(amount+1,-1);
        // int ans = solveUsingMemoization(coins,remAmount,dp);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;


        // bottom-up approach
        int ans = solveUsingTabulation(coins,amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;

    }
};

// Method 2 : 
// Uses 2D dp

class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int remAmount, int index){
        // base case
        if(remAmount == 0){
            return 0;
        }

        if(index >= coins.size()){
            return INT_MAX;
        }

        // Magic line
        int includeAns = INT_MAX;
        int excludeAns = INT_MAX;
        if(remAmount - coins[index] >= 0){
            int recAns = solveUsingRecursion(coins, remAmount - coins[index], index);
            if(recAns != INT_MAX){
                includeAns = 1 + recAns;
            }
        }

        excludeAns = 0 + solveUsingRecursion(coins, remAmount, index + 1);
        
        int currAns = min(includeAns, excludeAns);
        return currAns;
    }

    int solveUsingMemoization(vector<int>& coins, int remAmount, int index, vector<vector<int>> &dp){
        // base case
        if(remAmount == 0){
            return 0;
        }

        if(index >= coins.size()){
            return INT_MAX;
        }

        if(dp[remAmount][index] != -1){
            return dp[remAmount][index];
        }

        // Magic line
        int includeAns = INT_MAX;
        int excludeAns = INT_MAX;
        if(remAmount - coins[index] >= 0){
            int recAns = solveUsingMemoization(coins, remAmount - coins[index], index, dp);
            if(recAns != INT_MAX){
                includeAns = 1 + recAns;
            }
        }

        excludeAns = 0 + solveUsingMemoization(coins, remAmount, index + 1, dp);
        
        dp[remAmount][index] = min(includeAns, excludeAns);
        return dp[remAmount][index];
    }

    int solveUsingTabulation(vector<int>& coins, int remAmount){
        int n = coins.size();
        vector<vector<int>> dp(remAmount+1, vector<int>(n+1, -1));

        if(remAmount == 0){
            return 0;
        }

        for(int j=0;j<dp[0].size();j++){
            dp[0][j] = 0;
        }

        for(int i=0;i<dp.size();i++){
            dp[i][n] = INT_MAX;
        }

        // TOP DOWN : remAmount -> amount to 0 , index -> 0 to n
        for(int amt=1; amt <= remAmount ; amt++){
            for(int i = n-1;i >= 0;i--){
                int includeAns = INT_MAX;
                int excludeAns = INT_MAX;
                if(amt - coins[i] >= 0){
                    int recAns = dp[amt - coins[i]][i];
                    if(recAns != INT_MAX){
                        includeAns = 1 + recAns;
                    }
                }

                excludeAns = 0 + dp[amt][i+1];
                dp[amt][i] = min(includeAns, excludeAns);
            }
        }

        return dp[remAmount][0];

    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = solveUsingRecursion(coins, amount , 0);

        // memoization
        // vector<vector<int>> dp(amount+1, vector<int>(n+1, -1));
        // int ans = solveUsingMemoization(coins, amount, 0, dp);    

        int ans = solveUsingTabulation(coins, amount);

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

