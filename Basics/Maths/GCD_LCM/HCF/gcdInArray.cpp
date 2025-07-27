#include<iostream>
#include<vector>

using namespace std;

/*Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

int gcdUtility(int num1,int num2){
    if(num1 == 0){
        return num2;
    }
    if(num2 == 0){
        return num1;
    }
    while(num1 > 0 && num2 > 0){
        if(num1 > num2){
            num1 = num1-num2;
        }else{
            num2 = num2-num1;
        }
    }
    return num1 == 0 ? num2 : num1;
}

int findGCD(vector<int>& nums) {
    int n = nums.size();
    int maxAns = nums[0];
    int minAns = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i] < minAns){
            minAns = nums[i];
        }
        else if(nums[i] > maxAns){
            maxAns = nums[i];
        }
    }
    return gcdUtility(maxAns,minAns);
}