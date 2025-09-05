# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1 : Mark all negative elements as zero
        for(int i = 0; i < n ;i++){
            if(nums[i] <= 0){
                nums[i] = n + 1;
            }
        }

        // Step 2 : Mark the index nums[i]-1 of element a[i] as negative if it isnt already negative or zero
        for(int i = 0; i < n; i++){
            int temp = abs(nums[i]);
            if(temp - 1 >= 0 && temp - 1 < n && nums[ temp - 1 ] > 0){
                nums[ temp - 1 ] *= -1;
            }
        }

        // Step 3 : Find the first index (i) having positive element -> if exists then i+1 is answer else n + 1 is answer
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }

        return n + 1;
    }
};