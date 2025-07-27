#include <iostream>
#include <vector>
using namespace std;


// method 1 : 1D dp (BEST)
class Solution {
public:
    int solveUsingRecursion(vector<int>& days, vector<int>& costs,int index){
        // base case
        if(index >= days.size()){
            return 0;
        }
        // 1 case me solve
        // 1-day pass
        int option1 = costs[0] + solveUsingRecursion(days,costs,index+1);

        // 7 day pass
        int currDay = days[index];
        int endDay = currDay + 7 - 1;
        int j = index;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        int option2 = costs[1] + solveUsingRecursion(days,costs,j);

        // 30 day pass
        endDay = currDay + 30 - 1;
        j = index;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        int option3 = costs[2] + solveUsingRecursion(days,costs,j);

        return min(min(option1,option2),option3);
    }

    int solveUsingMemoization(vector<int>& days, vector<int>& costs,int index,vector<int> &dp){
        // base case
        if(index >= days.size()){
            return 0;
        }

        // step 3:
        if(dp[index] != -1){
            return dp[index];
        }

        // 1 case me solve
        // 1-day pass
        int option1 = costs[0] + solveUsingMemoization(days,costs,index+1,dp);

        // 7 day pass
        int currDay = days[index];
        int endDay = currDay + 7 - 1;
        int j = index;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        int option2 = costs[1] + solveUsingMemoization(days,costs,j,dp);

        // 30 day pass
        endDay = currDay + 30 - 1;
        j = index;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        int option3 = costs[2] + solveUsingMemoization(days,costs,j,dp);

        dp[index] = min(min(option1,option2),option3);
        return dp[index];
    }

    int solveUsingTabulation(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1,-1);

        dp[n] = 0;

        for(int index =n-1;index>=0;index--){
            // 1-day pass
            int option1 = costs[0] + dp[index+1];

            // 7 day pass
            int currDay = days[index];
            int endDay = currDay + 7 - 1;
            int j = index;
            while(j < days.size() && days[j] <= endDay){
                j++;
            }
            int option2 = costs[1] + dp[j];

            // 30 day pass
            endDay = currDay + 30 - 1;
            j = index;
            while(j < days.size() && days[j] <= endDay){
                j++;
            }
            int option3 = costs[2] + dp[j];

            dp[index] = min(min(option1,option2),option3);
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int index = 0;
        // return solveUsingRecursion(days,costs,index);

        // memoization
        // index : 0 to n
        // vector<int> dp(n+1,-1);
        // return solveUsingMemoization(days,costs,index,dp);

        // tabulation
        return solveUsingTabulation(days,costs);
    }
};

// method 2: 2D dp
class Solution {
public:
    int solveUsingRecursion(vector<int>& days, vector<int>& costs,int index,int endDay){
        // base case
        if(index >= days.size()){
            return 0;
        }

        // 1 case me solve remainining recursion will handle
        int minCost = INT_MAX;
        int currDay = days[index];
        if(endDay >= currDay){
            minCost = solveUsingRecursion(days,costs,index+1,endDay);
        }else{
            int option1 = costs[0] + solveUsingRecursion(days,costs,index+1,currDay);
            int option2 = costs[1] + solveUsingRecursion(days,costs,index+1,currDay+6);
            int option3 = costs[2] + solveUsingRecursion(days,costs,index+1,currDay+29);
            minCost = min(option1,min(option2,option3));
        }
        return minCost;
    }

    int solveUsingMemoization(vector<int>& days, vector<int>& costs,int index,int endDay,vector<vector<int>> &dp){
        // base case
        if(index >= days.size()){
            return 0;
        }
        // step 3:
        if(dp[index][endDay] != -1){
            return dp[index][endDay];
        }

        // 1 case me solve remainining recursion will handle
        int minCost = INT_MAX;
        int currDay = days[index];
        if(endDay >= currDay){
            minCost = solveUsingMemoization(days,costs,index+1,endDay,dp);
        }else{
            int option1 = costs[0] + solveUsingMemoization(days,costs,index+1,currDay,dp);
            int option2 = costs[1] + solveUsingMemoization(days,costs,index+1,currDay+6,dp);
            int option3 = costs[2] + solveUsingMemoization(days,costs,index+1,currDay+29,dp);
            minCost = min(option1,min(option2,option3));
        }
        dp[index][endDay] = minCost;
        return dp[index][endDay];
    }

    int solveUsingTabulation(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<vector<int>> dp(n+1,vector<int>(30+days[n-1],-1));

        for(int i=0;i < 30+days[n-1]; i++){
            dp[n][i] = 0;
        }

        // step 3 :
        for(int index = n-1; index >= 0 ;index--){
            for(int endDay = 29+days[n-1] ; endDay >= 0 ; endDay--){
                int minCost = INT_MAX;
                int currDay = days[index];
                if(endDay >= currDay){
                    minCost = dp[index+1][endDay];
                }else{
                    int option1 = costs[0] + dp[index+1][currDay];
                    int option2 = costs[1] + dp[index+1][currDay+6];
                    int option3 = costs[2] + dp[index+1][currDay+29];
                    minCost = min(option1,min(option2,option3));
                }
                dp[index][endDay] = minCost;
            }
        }

        return dp[0][0];

    }

    int solveUsingTabulationSpaceOptimisation(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> nextRow(30+days[n-1],-1);
        vector<int> currRow(30+days[n-1],-1);

        for(int i=0;i < 30+days[n-1]; i++){
            nextRow[i] = 0;
        }

        for(int index = n-1; index >= 0 ;index--){
            for(int endDay = 29+days[n-1] ; endDay >= 0 ; endDay--){
                int minCost = INT_MAX;
                int currDay = days[index];
                if(endDay >= currDay){
                    minCost =   nextRow[endDay];
                }else{
                    int option1 = costs[0] + nextRow[currDay];
                    int option2 = costs[1] + nextRow[currDay+6];
                    int option3 = costs[2] + nextRow[currDay+29];
                    minCost = min(option1,min(option2,option3));
                }
                currRow[endDay] = minCost;
            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int endDay = 0;
        int index  = 0;
        
        // return solveUsingRecursion(days,costs,index,endDay);

        // memoization
        // index : 0 to n , endDay : 0 to days[n-1] + 29

        // vector<vector<int>> dp(n+1,vector<int>(30+days[n-1],-1));
        // return solveUsingMemoization(days,costs,index,endDay,dp);

        // return solveUsingTabulation(days,costs);

        return solveUsingTabulationSpaceOptimisation(days,costs);

    }
};

