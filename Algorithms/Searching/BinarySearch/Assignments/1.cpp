#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// Method 2 : Using hashing on the way concept
class Solution1 {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_set<int> visited;
        // I took below map so that no duplicate pairs occurs because map allows only unique key
        // In this map we store in format of (min,max) so that duplicate pairs will not be stored again .
        unordered_map<int,int> ans;
        // i can use set<pair<int,int> also but not unordered_set

        for(int i=0;i<nums.size();i++){
            bool c1 = (visited.count(nums[i]-k) == 1);
            bool c2 = (visited.count(nums[i]+k) == 1);

            if(c1){
                ans.insert(make_pair(min(nums[i],nums[i]-k),max(nums[i],nums[i]-k)));
            }
            if(c2){
                ans.insert(make_pair(min(nums[i],nums[i]+k),max(nums[i],nums[i]+k)));
            }

            visited.insert(nums[i]);
        }
        return ans.size();
    }
};

// Method 3 : Using two pointer
class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        // sort
        sort(nums.begin(),nums.end());

        set<pair<int,int>> ans;

        int i=0;
        int j = 1;
        while(j<nums.size()){
            int diff = nums[j]-nums[i];
            if(diff == k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }else if(diff > k){
                i++;
            }else{
                j++;
            }
            // Important will forget
            if(i == j){
                j++;
            }
        }

        return ans.size();
    }
};

// Method 4:
class Solution {
public:
    bool binSearch(vector<int>& nums,int start,int target){
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start <= end){
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }

        return false;
    }

    int findPairs(vector<int>& nums, int k) {
        // sort
        sort(nums.begin(),nums.end());

        set<pair<int,int>> ans;

        for(int i=0;i<nums.size();i++){
            if(binSearch(nums,i+1,nums[i]+k) != false){
                ans.insert({nums[i],nums[i]+k});
            }
        }

        return ans.size();
    }
};

