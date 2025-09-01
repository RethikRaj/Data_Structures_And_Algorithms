#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int insertionIndex = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                insertionIndex++;
                nums[insertionIndex] = nums[i];
            }
        }
        return insertionIndex + 1;
    }
};