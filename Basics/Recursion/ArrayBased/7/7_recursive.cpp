#include<iostream>
#include <vector>
using namespace std;

void maxProfitUtil(vector<int>& prices,int index,int& minPrice,int& maxProfit){
    if(index >= prices.size()){
        return;
    }
    // 1 case me solve
    // Update minPrice
    minPrice = min(prices[index],minPrice);
    // Sell & Update maxProfit
    int todayProfit = prices[index]-minPrice;
    maxProfit = max(todayProfit,maxProfit);
    // Remaining Recursion
    maxProfitUtil(prices,index+1,minPrice,maxProfit);
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitUtil(prices,0,minPrice,maxProfit);
    return maxProfit;
}