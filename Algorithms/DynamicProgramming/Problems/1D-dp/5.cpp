#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    long long mod = 1000000007;
    
    long long solveUsingRecursion(int n,int k){
        // base case
        if(n == 1){
            return k%mod;
        }
        if(n == 2){
            return (k*k)%mod;
        }
        
        long long recAns = ( solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k) )% mod;
        long long ans = ((k-1)*recAns)%mod;
        return ans;
    }
    
    long long solveUsingMemoization(int n,long long k,vector<long long> &dp){
        // base case
        if(n == 1){
            return k%mod;
        }
        if(n == 2){
            return (k*k)%mod;
        }
        // step 3
        if(dp[n] != -1){
            return dp[n];
        }
        
        long long recAns = ( solveUsingMemoization(n-1,k,dp) + solveUsingMemoization(n-2,k,dp) )% mod;
        // step 2
        dp[n] = ((k-1)*recAns)%mod;
        return dp[n];
    }
    
    long long solveUsingTabulation(int n,long long k){
        // step 1
        vector<long long> dp(n+1,-1);
        // step2
        dp[1] = k%mod;
        dp[2] = (k*k)%mod;
        
        // step 3 : n goes from n to 1 => reverse it and copy paste logic
        for(int i=3;i<=n;i++){
            long long recAns = (dp[i-1] + dp[i-2]) % mod;
            dp[i] = ((k-1)*recAns)%mod;
        }
        
        return dp[n];
    
    }
    
    long long solveUsingTabulationSpaceOptimised(int n,long long k){
        long long prev2 = k%mod;
        if(n == 1){
            return prev2;
        }
        long long prev1 = (k*k)%mod;
        if(n == 2){
            return prev1;
        }
        
        for(int i=3;i<=n;i++){
            long long recAns = (prev1 + prev2) % mod;
            long long curr = ((k-1)*recAns)%mod;
            
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
        
    }
    
    long long countWays(int n, int k){
        //return solveUsingRecursion(n,k);
        
        // step 1 : n : n to 1 => i need indexes from 1 to n
        //vector<long long> dp(n,-1); // => here i get indexes only 0 to n-1 => i need to map  => replace dp[n] by dp[n-1]
        vector<long long> dp(n+1,-1);
        return solveUsingMemoization(n,k,dp);
        
        //return solveUsingTabulation(n,k);
        
        //return solveUsingTabulationSpaceOptimised(n,k);
        
    }
};

