#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // prevIndex refer to the index of the element which is lastly included in the subsequence
    int solveUsingRecursion(vector<int> &nums, int index, int prevIndex){
        // BC
        if(index >= nums.size()){
            return 0;
        }
        // Magic line
        int includeAns = 0;
        int excludeAns = 0;
        if(prevIndex == -1 || nums[prevIndex] < nums[index] ){
            includeAns = 1 + solveUsingRecursion(nums, index+1, index);
        }
        excludeAns = 0 + solveUsingRecursion(nums, index+1, prevIndex);
        int currAns = max(includeAns, excludeAns);
        return currAns;
    }

    int solveUsingMemoization(vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp){
        // BC
        if(index >= nums.size()){
            return 0;
        }
        
        if(dp[index][prevIndex + 1] != -1){
            return dp[index][prevIndex + 1];
        }

        // Magic line
        int includeAns = 0;
        int excludeAns = 0;
        if(prevIndex == -1 || ( nums[prevIndex] < nums[index] )){
            includeAns = 1 + solveUsingMemoization(nums, index+1, index, dp);
        }
        excludeAns = 0 + solveUsingMemoization(nums, index+1, prevIndex, dp);
        dp[index][prevIndex + 1] = max(includeAns, excludeAns);
        return dp[index][prevIndex + 1];
    }

    int solveUsingTabulation(vector<int>& nums){
        int n = nums.size();
        // Step 1 : 
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        // step 2 : index(0 to n) >= n => only index = n >= n -> initialise with zero 
        for(int j=0;j<=n;j++){
            dp[n][j] = 0;
        }

        // Step 3: In top down index: 0 to n, prevIndex goes from -1 to index-1
        for(int index = n-1; index >=0 ;index--){
            for(int prevIndex = index-1; prevIndex >= -1; prevIndex--){
                int includeAns = 0;
                int excludeAns = 0;
                if(prevIndex == -1 || ( nums[prevIndex] < nums[index] )){
                    includeAns = 1 + dp[index+1][index + 1]; // index+1 is done in colIndex because we are shifting
                }
                excludeAns = 0 + dp[index+1][prevIndex + 1];// prevIndex+1 is done in colIndex because we are shifting
                dp[index][prevIndex + 1] = max(includeAns, excludeAns);
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int ans = solveUsingRecursion(nums, 0, -1);
        
        // index goes from (0 to n) 
        // and prevIndex goes from (-1 to index-1) => maximum prevIndex goes from (-1 to n-1) 
        // Therefore 2D dp => (n+1)*(n+1)

        // But when prevIndex == -1 we cant acces negative indexes => shift (-1 -> 0 ), (0 -> 1) , ... , (n-1 to n)
        // In memoization approach i have used dp[..][prevIndex+1] for this shifting purpose
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMemoization(nums, 0, -1, dp);

        int ans = solveUsingTabulation(nums);
        return ans;
    }
};