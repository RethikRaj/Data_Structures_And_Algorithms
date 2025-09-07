// Intersection of Two Arrays -II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1 :
    vector<int> freqApproach(vector<int>& arr1, vector<int>& arr2){
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i=0;i < arr1.size();i++){
            if(mp.find(arr1[i]) == mp.end()){
                mp[arr1[i]] = 1;
            }else{
                mp[arr1[i]] += 1;
            }
        }

        for(int i=0; i < arr2.size(); i++){
            int currEle = arr2[i];
            // Check whether currEle is found and its freq is > 0
            if(mp.find(currEle) != mp.end() && mp[currEle] > 0){
                ans.push_back(currEle);
                mp[currEle] -= 1;
            }
        }

        return ans;
    }

    // Method 2 :

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

            cout <<curr << ":" <<lb1 << " " << ub1 << " " << lb2 << " " << ub2 << endl;

            int minimumOccurences = min(totalOccurences1, totalOccurences2);

            for(int j = 0;j < minimumOccurences; j++){
                ans.push_back(curr);
            }

            // Updation of i => Skipp all indexes where the ele is equal to curr
            i = ub1;
        }

        return ans;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // return freqApproach(nums1, nums2);

        return binarySearchApproach(nums1, nums2);
    }
};