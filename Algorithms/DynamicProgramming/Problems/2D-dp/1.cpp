#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
  
    int solveUsingRecursion(int remCapacity, vector<int>& wt, vector<int>& val,int index){
        // base case
        if(remCapacity <= 0){
            return 0;
        }
        if(index >= wt.size()){
            return 0;
        }
        
        // 1 case me solve remaining recursion will handle
        int include = 0;
        if(remCapacity >= wt[index]){
            // if included profit increases bt val[index]
            include = val[index] + solveUsingRecursion(remCapacity-wt[index],wt,val,index+1);
        }
        int exclude = 0 + solveUsingRecursion(remCapacity,wt,val,index+1);
        
        int ans = max(include,exclude);
        return ans;
    }
    
    int solveUsingMemoization(int remCapacity, vector<int>& wt, vector<int>& val,int index,vector<vector<int>> &dp){
        // base case
        if(remCapacity <= 0){
            return 0;
        }
        if(index >= wt.size()){
            return 0;
        }
        
        // step 3 :
        if(dp[remCapacity][index] != -1){
            return dp[remCapacity][index];
        }
        
        // 1 case me solve remaining recursion will handle
        int include = 0;
        if(remCapacity >= wt[index]){
            // if included profit increases bt val[index]
            include = val[index] + solveUsingMemoization(remCapacity-wt[index],wt,val,index+1,dp);
        }
        int exclude = 0 + solveUsingMemoization(remCapacity,wt,val,index+1,dp);
        
        // step 2 :
        dp[remCapacity][index] = max(include,exclude);
        return dp[remCapacity][index];
    }
    
    int solveUsingTabulation(int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();
        // step 1 :
        // row : remCapacity : W to 0 => size : (W+1)
        // col : index : 0 to n => size : (n+1)
        vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
        
        // step2 : analyse base cases and update dp array 
        // instead of doing this i can also just initialise the dp array with 0
        for(int col = 0;col < n+1;col++){
            dp[0][col] = 0;
        }
        
        for(int row = 0;row < W+1;row++){
            dp[row][n] = 0;
        }
        
        
        // step 3 : remCapacity : W to 0 , index : 0 to n => reverse it and copy-paste logic
        for(int remCapacity = 1;remCapacity <= W;remCapacity++){
            for(int index = n-1;index >= 0;index--){
                int include = 0;
                if(remCapacity >= wt[index]){
                    // if included profit increases bt val[index]
                    include = val[index] + dp[remCapacity-wt[index]][index+1];
                }
                int exclude = 0 + dp[remCapacity][index+1];
                
                dp[remCapacity][index] = max(include,exclude);
            }
        }
        
        return dp[W][0];
    }
    
    int solveUsingTabulationSpaceOptimisation(int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();
        
        vector<int> nextCol(W+1,0);
        vector<int> currCol(W+1,0);
        
        for(int index = n-1;index >= 0;index--){
            for(int remCapacity = 1;remCapacity <= W;remCapacity++){
                int include = 0;
                if(remCapacity >= wt[index]){
                    //include = val[index] + dp[remCapacity-wt[index]][index+1];
                    include = val[index] + nextCol[remCapacity-wt[index]];
                }
                int exclude = 0 + nextCol[remCapacity];
                
                currCol[remCapacity] = max(include,exclude);
            }
            // shifting => IMPPPPPP
            nextCol = currCol;
        }
        
        return nextCol[W];
    }
    
    int solveUsingTabulationSpaceOptimisation2(int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();
        
        vector<int> currCol(W+1,0);
        
        for(int index = n-1;index >= 0;index--){
            for(int remCapacity = W;remCapacity >= 1;remCapacity--){
                int include = 0;
                if(remCapacity >= wt[index]){
                    //include = val[index] + dp[remCapacity-wt[index]][index+1];
                    include = val[index] + currCol[remCapacity-wt[index]];
                }
                int exclude = 0 + currCol[remCapacity];
                
                currCol[remCapacity] = max(include,exclude);
            }
        }
        
        return currCol[W];
    }
    
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        int remCapacity = W;
        int index = 0;
        // return solveUsingRecursion(remCapacity,wt,val,index);
        
        // memoization
        // step 1:
        // row : remCapacity : W to 0 => size : (W+1)
        // col : index : 0 to n => size : (n+1)
        // vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
        // return solveUsingMemoization(remCapacity,wt,val,index,dp);
        
        // tabulation
        //return solveUsingTabulation(W,wt,val);
        
        // space optimisation(Single level) => SC : O(W+W)
        //return solveUsingTabulationSpaceOptimisation(W,wt,val);
        
        // space optimisation => SC : O(W)
        return solveUsingTabulationSpaceOptimisation2(W,wt,val);
    }
};

