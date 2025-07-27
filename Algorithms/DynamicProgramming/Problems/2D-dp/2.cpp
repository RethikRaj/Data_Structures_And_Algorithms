#include <iostream>
#include <vector>

using namespace std;

// method 1 
class Solution {
public:
    bool solveUsingRecursion(vector<int> &nums,int index,int subsetOneSum,int &totalSum){
        // base case
        if(index >= nums.size()){
            int subsetTwoSum = totalSum - subsetOneSum;
            
            return subsetOneSum == subsetTwoSum;
        }

        // 1 case me solve remainining recursion will handle
        bool option1 = solveUsingRecursion(nums,index+1,subsetOneSum+nums[index],totalSum); // include in subsetOne
        bool option2 = solveUsingRecursion(nums,index+1,subsetOneSum,totalSum); // exclude in subsetOne

        return option1 || option2; 
    }

    bool solveUsingMemoization(vector<int> &nums,int index,int subsetOneSum,int &totalSum,vector<vector<int>> &dp){
        // base case
        if(index >= nums.size()){
            int subsetTwoSum = totalSum - subsetOneSum;
            return subsetOneSum == subsetTwoSum;
        }

        if(dp[index][subsetOneSum] != -1){
            return dp[index][subsetOneSum];
        }


        // 1 case me solve remainining recursion will handle
        bool option1 = solveUsingMemoization(nums,index+1,subsetOneSum+nums[index],totalSum,dp); // include in subsetOne
        bool option2 = solveUsingMemoization(nums,index+1,subsetOneSum,totalSum,dp); // exclude in subsetOne

        dp[index][subsetOneSum] = option1 || option2; 
        return dp[index][subsetOneSum];
    }

    bool solveUsingTabulation(vector<int> &nums,int &totalSum){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(totalSum+1,-1));

        // step 2:
        for(int col = 0 ; col <= totalSum ; col++){
            if(totalSum - col == col){
                dp[n][col] = true;
            }
            else{
                dp[n][col] = false;
            }
        }

        // step 3 : index : 0 to n , subsetOneSum : 0 to totalSum => reverse it
        for(int index = n-1 ; index >= 0 ;index--){
            for(int j = totalSum ; j >= 0 ; j--){
                bool option1 = false;
                if(j + nums[index] <= totalSum){
                    option1 = dp[index+1][j+nums[index]]; 
                }
                bool option2 = dp[index+1][j]; 

                dp[index][j] = option1 || option2; 
            }
        }

        return dp[0][0];
    }

    bool solveUsingTabulationSpaceOptimisation(vector<int> &nums,int &totalSum){
        int n = nums.size();

        vector<bool> nextRow(totalSum+1,false);
        for(int col = 0 ; col <= totalSum ; col++){
            if(totalSum - col == col){
                nextRow[col] = true;
            }
            else{
                nextRow[col] = false;
            }
        }

        vector<bool> currRow(totalSum+1,false);

        // step 3 : index : 0 to n , subsetOneSum : 0 to totalSum => reverse it
        for(int index = n-1 ; index >= 0 ;index--){
            for(int j = totalSum ; j >= 0 ; j--){
                bool option1 = false;
                if(j + nums[index] <= totalSum){
                    option1 = nextRow[j+nums[index]]; 
                }
                bool option2 = nextRow[j]; 

                currRow[j] = option1 || option2; 
            }
            // shifting => IMMMMMMPPPPPP
            nextRow = currRow;
        }

        return nextRow[0];
    }

    bool solveUsingTabulationSpaceOptimisation2(vector<int> &nums,int &totalSum){
        int n = nums.size();

        vector<bool> currRow(totalSum+1,false);
        for(int col = 0 ; col <= totalSum ; col++){
            if(totalSum - col == col){
                currRow[col] = true;
            }
            else{
                currRow[col] = false;
            }
        }

        // step 3 : index : 0 to n , subsetOneSum : 0 to totalSum => reverse it
        for(int index = n-1 ; index >= 0 ;index--){
            for(int j = 0 ; j <= totalSum; j++){
                bool option1 = false;
                if(j + nums[index] <= totalSum){
                    option1 = currRow[j+nums[index]]; 
                }
                bool option2 = currRow[j]; 

                currRow[j] = option1 || option2; 
            }
            
        }

        return currRow[0];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i < n;i++){
            totalSum += nums[i];
        }

        int index = 0;
        int subsetOneSum = 0;

        // return solveUsingRecursion(nums,index,subsetOneSum,totalSum);

        // Memoization
        // step 1 : index : 0 to n , subsetOneSum : 0 to totalSum;
        // vector<vector<int>> dp(n+1,vector<int>(totalSum+1,-1));
        // return solveUsingMemoization(nums,index,subsetOneSum,totalSum,dp);

        // tabulation
        //return solveUsingTabulation(nums,totalSum);

        //return solveUsingTabulationSpaceOptimisation(nums,totalSum);

        return solveUsingTabulationSpaceOptimisation2(nums,totalSum);
        
    }
};

// method 2 : PENDING => SEE ASSIGNMENT OR MEGA CLASS OF RECURSION