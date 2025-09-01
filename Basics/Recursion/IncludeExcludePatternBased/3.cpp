#include<iostream>
#include<vector>

using namespace std;


// Method 1 : Implementation 2
void countCoins(vector<int>& coins, int remainingAmount,int& minCoins,int numberOfCoins){
    // Base Case 
    if(remainingAmount == 0){
        // update minCoins
        minCoins = min(minCoins,numberOfCoins);
        return;
    }
    for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        if(coin <= remainingAmount){
            countCoins(coins,remainingAmount-coin,minCoins,numberOfCoins+1);
        }
    }
}

int coinChange(vector<int>& coins, int amount) {
    int minCoinsAns = INT_MAX;
    countCoins(coins,amount,minCoinsAns,0);
    if(minCoinsAns == INT_MAX){
        // Impossible to construct amount using these coin denominations
        return -1;
    }
    return minCoinsAns;
}


// Method 1 : Implementation 1

int countCoins(vector<int>& coins, int remainingAmount){
    // Base Case 
    if(remainingAmount == 0){
        // remainingAmount = 0 => no coins reqd to construct zero amount => no of coins reqd = 0;
        return 0;
    }
    // Since we need to find minimum number of coins required to construct the amount
    int minCoins = INT_MAX;
    // for each amount , all coin of the coins array is traveresed fully.
    for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        // 1 case me solve and remaining recursion will handle
        // only if coin <= remainingAmount => rec Call will be done
        if(coin <= remainingAmount){
            // Using this coin we get remainingAmout as remainingAmount - coin => 1 coin used here
            int recAns = countCoins(coins,remainingAmount-coin);
            // recAns may be valid or invalid
            // invalid meaning => impossible to create the remainingAmount using these coins
            // if invalid => ignore it => no use
            // therefore check valid => minCoins != INT_MAX
            if(recAns != INT_MAX){
                int coinsUsed = 1 + recAns;
                // Update minCoins
                minCoins = min(minCoins,coinsUsed);
            }
        }    
    }
    return minCoins;
}

int coinChange(vector<int>& coins, int amount) {
    int ans = countCoins(coins,amount);
    if(ans == INT_MAX){
        // Impossible to construct amount using these coin denominations
        return -1;
    }
    return ans;
} 


// Method 2 : Similar to other questions without using for loop
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

    

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingRecursion(coins, amount , 0);


        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};