#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1000000007;

    int solveUsingRecursion(int &n,int &k,int dieNo,int target){
        // base case
        if(dieNo == n){
            if(target == 0){
                return 1;
            }else{
                return 0;
            }
        }

        // 
        int totalways = 0;
        for(int face = 1;face <= k; face++){
            if(target >= face){
                totalways = (totalways + solveUsingRecursion(n,k,dieNo+1,target-face)) % mod;
            }
        }
        return totalways;
    }

    int solveUsingMemoization(int &n,int &k,int dieNo,int target,vector<vector<int>> &dp){
        // base case
        if(dieNo == n){
            if(target == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[dieNo][target] != -1){
            return dp[dieNo][target];
        }

        int totalways = 0;
        for(int face = 1;face <= k; face++){
            if(target >= face){
                totalways = (totalways + solveUsingMemoization(n,k,dieNo+1,target-face,dp)) % mod;
            }
        }
        dp[dieNo][target] =totalways;
        return dp[dieNo][target];
    }

    int solveUsingTabulation(int &n,int &k,int target){
        // step 1
        vector<vector<int>> dp(n+1,vector<int>(target+1,0)); // initialized with zero because of else case in base case

        // step 2
        dp[n][0] = 1;

        // step 3:
        for(int dieNo = n-1; dieNo >= 0 ; dieNo--){
            for(int t = 0 ; t <= target ; t++){
                int totalways = 0;
                for(int face = 1;face <= k; face++){
                    if(t >= face){
                        totalways = (totalways + dp[dieNo+1][t-face]) % mod;
                    }
                }
                dp[dieNo][t] =totalways;
            }
        }

        return dp[0][target];
    }

    int solveUsingTabulationSpaceOptimsation(int &n,int &k,int target){
        vector<int> nextRow(target+1,0);
        nextRow[0] = 1;
        vector<int> currRow(target+1,0);
        
        
        for(int dieNo = n-1; dieNo >= 0 ; dieNo--){
            for(int t = 0 ; t <= target ; t++){
                int totalways = 0;
                for(int face = 1;face <= k; face++){
                    if(t >= face){
                        totalways = (totalways + nextRow[t-face]) % mod;
                    }
                }
                currRow[t] = totalways;
            }
            // SHIFTING => IMPPPPP
            nextRow = currRow;
        }

        return nextRow[target];
    }

    int solveUsingTabulationSpaceOptimsation2(int &n,int &k,int target){
        vector<int> currRow(target+1,0);
        currRow[0] = 1;
        
        for(int dieNo = n-1; dieNo >= 0 ; dieNo--){
            for(int t = target ; t >= 0 ; t--){
                int totalways = 0;
                for(int face = 1;face <= k; face++){
                    if(t >= face){
                        totalways = (totalways + currRow[t-face]) % mod;
                    }
                }
                currRow[t] = totalways;
            }
        }

        return currRow[target];
    }


    int numRollsToTarget(int n, int k, int target) {
        int dieNo=0;
        // return solveUsingRecursion(n,k,dieNo,target);

        // memoization 
        // step 1 :dieNo : 0 to n , target : target to 0
        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return solveUsingMemoization(n,k,dieNo,target,dp);

        // tabulation
        //return solveUsingTabulation(n,k,target);

        //return solveUsingTabulationSpaceOptimsation(n,k,target);

        return solveUsingTabulationSpaceOptimsation2(n,k,target);
    }
};

// sir solution
class Solution {
public:
    long long int mod = 1000000007;
    int solveRec(int n , int k, int target) {
        //base case
        if(target < 0 || n < 0)
            return 0;
        if(n==0 && target==0) {
            return 1;
        }
        if(n==0 && target !=0 ){
            return 0;
        }
        if(n!=0 && target == 0) {
            return 0;
        }

        //recursive logic
        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += solveRec(n-1, k, target-i);
        }
        return ans;
    }///2D DP

    int solveMem(int n , int k, int target,vector<vector<long long int> >& dp) {
        //base case
        if(target < 0 || n < 0)
            return 0;
        if(n==0 && target==0) {
            return 1;
        }
        if(n==0 && target !=0 ){
            return 0;
        }
        if(n!=0 && target == 0) {
            return 0;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        //recursive logic
        long long int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += solveMem(n-1, k, target-i, dp);
        }
        dp[n][target] = ans % mod ;
        return dp[n][target];
    }


    int solveUsingTab(int n, int k, int target) {
        vector<vector<long long int> > dp(n+1, vector<long long int>(target+1, 0));

        dp[0][0] = 1;

        for(int N=1; N<=n; N++) {
            for(int t=1; t<=target; t++) {
                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int tempAns = 0;
                    if(t-i >= 0) {
                        tempAns = dp[N-1][t-i];
                    }
                    ans = (ans % mod) + (tempAns % mod) ;
                }
                dp[N][t] = ans % mod ;
            }
        }
        return dp[n][target];
    }

    int solveUsingTabSO(int n, int k, int target) {
        //vector<vector<long long int> > dp(n+1, vector<long long int>(target+1, 0));

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int N=1; N<=n; N++) {
            for(int t=1; t<=target; t++) {
                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int tempAns = 0;
                    if(t-i >= 0) {
                        tempAns = prev[t-i];
                    }
                    ans = (ans % mod) + (tempAns % mod) ;
                }
                curr[t] = ans % mod ;
            }
            //shifting
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        //return solveRec(n,k,target);   
        //vector<vector<long long int> > dp(n+1, vector<long long int>(target+1, -1));
        return solveUsingTabSO(n,k,target); 
    }
};