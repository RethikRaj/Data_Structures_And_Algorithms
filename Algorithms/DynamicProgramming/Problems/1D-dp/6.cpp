#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    void getAllPerfectSqauresLessThanN(int n,vector<int> &perfectSquares){
        int num = 1;
        while(num*num <= n){ // alternate condition : num <= sqrt(n)
            perfectSquares.push_back(num*num);
            num += 1;
        }
    }

    int solveUsingRecursion(int n,vector<int> &perfectSquares){
        // base case
        if(n == 0){
            return 0;
        }
        // 1 case me solve remaining recursion will handle
        int minAns = INT_MAX;
        for(int i=0;i < perfectSquares.size();i++){
            int curr = perfectSquares[i];
            if(curr <= n){
                int recAns = 1 + solveUsingRecursion(n-curr,perfectSquares);
                minAns = min(minAns,recAns);
            }
        }
        return minAns;
    }

    int solveUsingMemoization(int n,vector<int> &perfectSquares,vector<int> &dp){
        // base case
        if(n == 0){
            return 0;
        }
        // step 3 : 
        if(dp[n] != -1){
            return dp[n];
        }

        // 1 case me solve remaining recursion will handle
        int minAns = INT_MAX;
        for(int i=0;i < perfectSquares.size();i++){
            int curr = perfectSquares[i];
            if(curr <= n){
                int recAns = 1 + solveUsingMemoization(n-curr,perfectSquares,dp);
                minAns = min(minAns,recAns);
            }
        }
        // step 2;
        dp[n] = minAns;
        return minAns;
    }

    int solveUsingTabulation(int n,vector<int> &perfectSquares){
        vector<int> dp(n+1,-1);

        dp[0] = 0;

        for(int num = 1 ; num <= n ;num++){
            int minAns = INT_MAX;
            for(int i=0;i < perfectSquares.size();i++){
                int curr = perfectSquares[i];
                if(curr <= num){
                    int recAns = 1 + dp[num-curr];
                    minAns = min(minAns,recAns);
                }
            }
            dp[num] = minAns;
        }

        return dp[n];
    }

    int numSquares(int n) {
        vector<int> perfectSquares;
        getAllPerfectSqauresLessThanN(n,perfectSquares);

        // return solveUsingRecursion(n,perfectSquares);

        // memoization
        // step 1 : n : n to 0
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(n,perfectSquares,dp);

        return solveUsingTabulation(n,perfectSquares);

    }
};

// method 2 : no need to calculate perfectSquares beforeHand
class Solution {
public:
    int solveUsingRecursion(int n){
        // base case
        if(n == 0){
            return 0;
        }
        // 1 case me solve remaining recursion will handle
        int minAns = INT_MAX;
        int start = 1;
        int end = sqrt(n);
        while(start <= end){
            int perfectSquare = start*start;
            if(perfectSquare <= n){
                int recAns = 1 + solveUsingRecursion(n-perfectSquare);
                minAns = min(minAns,recAns);
            }
            start++;
        }
        return minAns;
    }

    int solveUsingMemoization(int n,vector<int> &dp){
        // base case
        if(n == 0){
            return 0;
        }
        // step 3 : 
        if(dp[n] != -1){
            return dp[n];
        }

        // 1 case me solve remaining recursion will handle
        int minAns = INT_MAX;
        int start = 1;
        int end = sqrt(n);
        while(start <= end){
            int perfectSquare = start*start;
            if(perfectSquare <= n){
                int recAns = 1 + solveUsingMemoization(n-perfectSquare,dp);
                minAns = min(minAns,recAns);
            }
            start++;
        }
        // step 2;
        dp[n] = minAns;
        return minAns;
    }

    int solveUsingTabulation(int n){
        vector<int> dp(n+1,-1);

        dp[0] = 0;

        for(int num = 1 ; num <= n ;num++){
            int minAns = INT_MAX;
            int start = 1;
            int end = sqrt(num);
            while(start <= end){
                int perfectSquare = start*start;
                if(perfectSquare <= num){
                    int recAns = 1 + dp[num-perfectSquare];
                    minAns = min(minAns,recAns);
                }
                start++;
            }
            // step 2;
            dp[num] = minAns;
        }

        return dp[n];
    }

    int numSquares(int n) {

        // return solveUsingRecursion(n);

        // memoization
        // step 1 : n : n to 0
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(n,dp);

        return solveUsingTabulation(n);

    }
};



