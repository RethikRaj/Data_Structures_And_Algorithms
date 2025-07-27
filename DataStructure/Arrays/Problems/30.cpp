#include <iostream>
#include <vector>

using namespace std;

class Solution{
    // two pointer approach => TC: O(n)
    vector<int> solve(vector<int> &A) {
        int indexOfFirstPositive = -1;
        int indexOfLastNegative = -1;
        
        for(int i=0;i<A.size();i++){
            if(A[i] >= 0){
                indexOfFirstPositive = i;
                break;
            }else{
                indexOfLastNegative = i;
            }
        }
        
        vector<int> ans;
        if(indexOfFirstPositive == -1){
            // all are neagtive numbers
            for(int i=A.size()-1;i>=0;i--){
                ans.push_back(A[i]*A[i]);
            }
            return ans;
        }
        
        if(indexOfLastNegative == -1){
            // all are +ve numbers
            for(int i=0;i<A.size();i++){
                ans.push_back(A[i]*A[i]);
            }
            return ans;
        }
        
        int i = indexOfLastNegative;
        int j = indexOfFirstPositive;
        
        
        while(i >= 0 && j < A.size()){
            if(A[i]*A[i] <= A[j]*A[j]){
                ans.push_back(A[i]*A[i]);
                i--;
            }else{
                ans.push_back(A[j]*A[j]);
                j++;
            }
        }
        
        while(i>=0){
            ans.push_back(A[i]*A[i]);
            i--;
        }
        
        while(j < A.size()){
            ans.push_back(A[j]*A[j]);
            j++;
        }
        
        return ans;
    }

    // two pointer simplified : TC : O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;

        vector<int> ans(nums.size());
        int z = nums.size()-1;

        while(i <= j){
            int numsOfISquared = nums[i]*nums[i];
            int numsOfJSquared = nums[j]*nums[j];

            if(numsOfISquared >= numsOfJSquared){
                ans[z] = numsOfISquared;
                i++;
            }else{
                ans[z] = numsOfJSquared;
                j--;
            }

            z--;
        }
        return ans;
    }    

    

};

