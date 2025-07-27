#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(string &text1,string &text2,int i,int j){
        // base case
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }

        // 1 case me solve remaining recursion will solve
        int maxLength = INT_MIN;
        if(text1[i] == text2[j]){
            maxLength = 1 + solveUsingRecursion(text1,text2,i+1,j+1);
        }
        else{
            int option1 = solveUsingRecursion(text1,text2,i+1,j);   // include text1[i] but exclude text2[j]
            int option2 = solveUsingRecursion(text1,text2,i,j+1);   // exclude text1[i] but include text2[j]
            maxLength = max(option1,option2);
        }
        return maxLength;
    }

    int solveUsingMemoization(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        // base case
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // 1 case me solve remaining recursion will solve
        int maxLength = INT_MIN;
        if(text1[i] == text2[j]){
            maxLength = 1 + solveUsingMemoization(text1,text2,i+1,j+1,dp);
        }
        else{
            int option1 = solveUsingMemoization(text1,text2,i+1,j,dp);   // include text1[i] but exclude text2[j]
            int option2 = solveUsingMemoization(text1,text2,i,j+1,dp);   // exclude text1[i] but include text2[j]
            maxLength = max(option1,option2);
        }
        dp[i][j] =  maxLength;
        return dp[i][j];
    }

    int solveUsingTabulation(string &text1,string &text2){
        // step 1
        vector<vector<int>> dp(text1.length()+1, vector<int> (text2.length()+1,0));

        // step 2 : I have already initialise with zero => No need

        // step 3 : 
        // i : 0 to text1.length() , j : 0 to text2.length() 
        // reverse : i : text1.length() to 0 , j : text2.length() to 0 but since i == text1.length , j == text2.length() is base case we dont include them in loop
        for(int i = text1.length()-1 ; i >= 0 ;i--){
            for(int j = text2.length()-1; j >= 0;j--){
                int maxLength = INT_MIN;
                if(text1[i] == text2[j]){
                    maxLength = 1 + dp[i+1][j+1];
                }
                else{
                    int option1 = dp[i+1][j];   // include text1[i] but exclude text2[j]
                    int option2 = dp[i][j+1];   // exclude text1[i] but include text2[j]
                    maxLength = max(option1,option2);
                }
                dp[i][j] =  maxLength;
            }
        }

        return dp[0][0];
    }

    int solveUsingTabulationSpaceOptimisation(string &text1,string &text2){
        vector<int> nextRow(text2.length()+1,0);
        vector<int> currRow(text2.length()+1,0);
        
        
        for(int i = text1.length()-1 ; i >= 0 ;i--){
            for(int j = text2.length()-1; j >= 0;j--){
                int maxLength = INT_MIN;
                if(text1[i] == text2[j]){
                    maxLength = 1 + nextRow[j+1];
                }
                else{
                    int option1 = nextRow[j];   // include text1[i] but exclude text2[j]
                    int option2 = currRow[j+1];   // exclude text1[i] but include text2[j]
                    maxLength = max(option1,option2);
                }
                currRow[j] =  maxLength;
            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }
        
   

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // recursion
        //return solveUsingRecursion(text1,text2,i,j);

        // memoization
        // i : 0 to text1.length() , j : 0 to text2.length()
        // vector<vector<int>> dp(text1.length()+1, vector<int> (text2.length()+1,-1));
        // return solveUsingMemoization(text1,text2,i,j,dp);

        // tabulation
        // return solveUsingTabulation(text1,text2);

        // space optimisation
        return solveUsingTabulationSpaceOptimisation(text1,text2);
    }
};
