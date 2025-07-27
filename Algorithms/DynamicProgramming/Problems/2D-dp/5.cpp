#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(int &m,int &n,int i,int j){
        // base case
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }

        // 1 case me solve remaining recurison will handle
        int option1 = solveUsingRecursion(m,n,i,j+1); // right
        int option2 = solveUsingRecursion(m,n,i+1,j); // down
        int totalWays = option1 + option2;
        return totalWays;
    }

    int solveUsingMemoization(int &m,int &n,int i,int j,vector<vector<int>> &dp){
        // base case
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // 1 case me solve remaining recurison will handle
        int option1 = solveUsingMemoization(m,n,i,j+1,dp); // right
        int option2 = solveUsingMemoization(m,n,i+1,j,dp); // down
        dp[i][j] = option1 + option2;
        return dp[i][j];
    }

    int solveUsingTabulation(int &m,int &n){
        // step1:
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // initialized with zero to take care of 2nd base case
        // step 2:
        dp[m-1][n-1] = 1;

        // step 3 : 
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1; j >= 0 ;j--){
                if(i == m-1 && j== n-1){
                    continue;
                }
                int option1 = dp[i][j+1]; // right
                int option2 = dp[i+1][j]; // down
                dp[i][j] = option1 + option2;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSpaceOptimisation(int &m,int &n){
        vector<int> nextRow(n+1,0);
        vector<int> currRow(n+1,0);
        currRow[n-1] = 1;

        // step 3 : 
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1; j >= 0 ;j--){
                if(i == m-1 && j== n-1){
                    continue;
                }
                int option1 = currRow[j+1]; // right
                int option2 = nextRow[j]; // down
                currRow[j] = option1 + option2;
            }
            // shifting => IMPPPPPP
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int solveUsingTabulationSpaceOptimisation2(int &m,int &n){
        vector<int> currRow(n+1,0);
        currRow[n-1] = 1;

        // step 3 : 
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1; j >=0 ;j--){
                if(i == m-1 && j== n-1){
                    continue;
                }
                int option1 = currRow[j+1]; // right
                int option2 = currRow[j]; // down
                currRow[j] = option1 + option2;
            }
        }
        return currRow[0];
    }

    int uniquePaths(int m, int n) {
        int i =0;
        int j =0;
        // return solveUsingRecursion(m,n,i,j);

        // memoization
        //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //return solveUsingMemoization(m,n,i,j,dp);

        // tabulation
        // return solveUsingTabulation(m,n);

        // return solveUsingTabulationSpaceOptimisation(m,n);

        return solveUsingTabulationSpaceOptimisation2(m,n);
    }
};
