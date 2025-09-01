#include <bits/stdc++.h>
using namespace std;

// Method 1: Brute Force => Rotate one by one and check is sorted => TC: O(n^2), SC: O(1)
class Solution {
public:
    bool isSorted(vector<int> &nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return true;
        }

        for(int rotationCount = 0; rotationCount < n; rotationCount++){
            // left rotate by one and then check is sorted
            int temp = nums[0];
            for(int i=0;i<n-1;i++){
                nums[i] = nums[i+1];
            }
            nums[n-1] = temp;
            bool ans = isSorted(nums);
            if(ans){
                return ans;
            }
        }

        return false;
    }
};

// Method 2: Optimal =>  Number of pairs with nums[i-1] > nums[i] is == 0 or == 1 =>TC: O(n), SC: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int numberOfPairs = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                numberOfPairs++;
            }
        }
        if(nums[nums.size()-1] > nums[0]){
            numberOfPairs++;
        }

        return numberOfPairs == 1 || numberOfPairs == 0;
    }
};