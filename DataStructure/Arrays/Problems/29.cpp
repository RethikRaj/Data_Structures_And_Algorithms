#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Using Map : TC:O(n) , SC:O(n)
    int method1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] += 1;
            if(mp[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }

    // sort and processing => TC: O(nlogn), SC:O(1)
    int method2(vector<int> &nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());

        int ele1 = nums[0];
        int count = 1; // counts the freq of ele1
        for(int i=1;i<n;i++){
            if(nums[i] == ele1){
                count++;
                if(count > n/2){
                    return ele1;
                }
            }else{
                ele1 = nums[i];
                count = 1;
            }
        }
        return -1;
    }

    // 
    

    int majorityElement(vector<int>& nums) {
        return method1(nums);
    }
};