#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bruteForce(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            while(j != i){
                if(arr[j] > arr[i]){
                    ans[i] = arr[j];
                    break;
                }
                else{
                    j = (j+1)%n;
                }
            }
            if(j == i){
                ans[i] = -1;
            }
        }
        return ans;
    }

    vector<int> optimalApproach(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> s;

        // find index of maxElement => WHY? => Because NGE of maxElement is always -1
        int maxIndex = 0;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[maxIndex]){
                maxIndex = i;
            }
        }

        // solving
        
        // making initial states
        s.push(INT_MAX);
        s.push(arr[maxIndex]);// imp
        ans[maxIndex] = -1; // store ans of maxIndex beforehand
        int index = maxIndex-1;
        // if maxIndex == 0 => index == -1 => make it circulate => index = n-1
        if(index < 0){
            index = n-1;
        }
        while(index != maxIndex){
            int curr = arr[index];
            // pop the stack till we reach -1 or we get greater element than curr
            while(!s.empty()  && s.top() <= curr){
                s.pop();
            }
            // store ans
            if(s.top() == INT_MAX){
                ans[index] = -1;
            }else{
                ans[index] = s.top();
            }
            // push the curr element
            s.push(curr);

            // update index
            if(index == 0){
                index = n-1;
            }else{
                index = index-1;
            }
        }
        return ans;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        //return bruteForce(nums);

        return optimalApproach(nums);
    }
};