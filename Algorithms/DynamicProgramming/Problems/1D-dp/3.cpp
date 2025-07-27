#include <iostream>
#include <vector>

using namespace std;

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

