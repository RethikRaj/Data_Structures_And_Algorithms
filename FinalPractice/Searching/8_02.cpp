// Intersection of arrays 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> setApproach(vector<int> &arr1, vector<int> &arr2){
        unordered_set<int> st(arr1.begin(), arr1.end());
        
        unordered_set<int> result;

        for(int i=0;i<arr2.size();i++){
            if(st.find(arr2[i]) != st.end()){
                result.insert(arr2[i]);
            }
        }

        vector<int> ans(result.begin(), result.end());
        return ans;
    }

    int indexOfLowerBound(vector<int> &arr, int target){
        int low = 0;
        int high = arr.size() - 1;

        int ans = arr.size();
        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int indexOfUpperBound(vector<int> &arr, int target){
        int low = 0;
        int high = arr.size() - 1;

        int ans = arr.size();
        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> binarySearchApproach(vector<int>& arr1, vector<int>& arr2){
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        vector<int> ans;
        
        int i = 0;
        while(i < arr1.size()){
            int curr = arr1[i];

            int lb1 = indexOfLowerBound(arr1, curr);
            int ub1 = indexOfUpperBound(arr1, curr);
            int totalOccurences1 = ub1 - lb1;

            int lb2 = indexOfLowerBound(arr2, curr);
            int ub2 = indexOfUpperBound(arr2, curr);
            int totalOccurences2 = ub2 - lb2;

            // Push only once if curr exist in both arra
            if(totalOccurences1 > 0 && totalOccurences2 > 0){
                ans.push_back(curr);
            }

            // Updation of i => Skipp all indexes where the ele is equal to curr
            i = ub1;
        }

        return ans;

    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // return setApproach(nums1, nums2);

        return binarySearchApproach(nums1, nums2);
    }
};