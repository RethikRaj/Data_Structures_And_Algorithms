#include<iostream>
#include <vector>
using namespace std;

// Method 1 : (Best)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minPriceTillThisDay = INT_MAX; // stores the minPrice from 0th to (i)th day
    int maxProfitTillThisDay = INT_MIN; 
    for(int i=0;i<n;i++){
        // We are in day i
        // Update minPrice 
        minPriceTillThisDay = min(prices[i],minPriceTillThisDay);
        // sell & update maxProfit
        int todayProfit = prices[i]-minPriceTillThisDay;
        maxProfitTillThisDay = max(todayProfit,maxProfitTillThisDay);
    }
    return maxProfitTillThisDay;
}


// Method 2 : Dont see
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 1){
        return 0;
    }

    int index = 1;
    int i = 0;
    int j = 1;
    int lastMin = i;
    int lastMax = j;
    while(index < n){
        if(index < n-1 && prices[i] > prices[index]){
            if(prices[j]-prices[i] > prices[lastMax]-prices[lastMin]){
                lastMin = i;
                lastMax = j;
            }
            i = index;
            j = i+1;
        }
        else if(prices[j] < prices[index]){
            if(prices[j]-prices[i] > prices[lastMax]-prices[lastMin]){
                lastMin = i;
                lastMax = j;
            }
            j = index;
        }
        index++;
    }
    int ans = max(prices[lastMax]-prices[lastMin],prices[j]-prices[i]);
    return ans >= 0 ? ans : 0;
}