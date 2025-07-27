#include<iostream>
#include<vector>

using namespace std;

int houseRobberOne(vector<int>& nums,int start,int end){
    // Base case
    if(start > end){
        return 0;
    }
    // Include
    int profitInclude = nums[start] + houseRobberOne(nums,start+2,end);
    // Exclude
    int profitExclude = 0 + houseRobberOne(nums,start+1,end);
    // return maximum profit
    return max(profitInclude,profitExclude);
}

int rob(vector<int>& nums) {
    int n = nums.size();

    int zerothHouseIncluded = nums[0] + houseRobberOne(nums,2,n-2);

    int zerothHouseExcluded = 0 + houseRobberOne(nums,1,n-1);   
    
    return max(zerothHouseIncluded,zerothHouseExcluded); 
}