#include<iostream>
#include<vector>

using namespace std;

// Method 1 : TLE
int robUtil(vector<int>& nums,int index){
    // base case
    if(index >= nums.size()){
        return 0;
    }
    // 1 case me solve remaining recursion
    // Include
    int profitInclude = nums[index] + robUtil(nums,index+2);
    // Exclude
    int profitExclude = 0 + robUtil(nums,index+1);

    // return max(profitInclude,profitExclude)
    return max(profitInclude,profitExclude);
}

int rob(vector<int>& nums) {
    int index = 0;
    return robUtil(nums,index);
}

// Method 2 : TLE
void robUtil(vector<int>& nums,int index,int& maxProfit,int profit){
    // base case
    if(index >= nums.size()){
        maxProfit = max(maxProfit,profit);
        return;
    }
    // 1 case me solve remaining recursion
    // Include
    robUtil(nums,index+2,maxProfit,profit+nums[index]);
    // Exclude
    robUtil(nums,index+1,maxProfit,profit);
}

int rob(vector<int>& nums) {
    int index = 0;
    int maxProfit = INT_MIN;
    int profit = 0;
    robUtil(nums,index,maxProfit,profit);
    return maxProfit;
}