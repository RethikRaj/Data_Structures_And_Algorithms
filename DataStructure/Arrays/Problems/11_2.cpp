#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueIndex = 0;
        int uniqueCount = 1;
        bool canInsert = true;

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[uniqueIndex]){
                uniqueCount++;
                if(uniqueCount > 2){
                    canInsert = false;
                }
            }else {
                uniqueCount = 1;
                canInsert = true; 
            }

            if(canInsert){
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }

        return uniqueIndex + 1;
    }
};