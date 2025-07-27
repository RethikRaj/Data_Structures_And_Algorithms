#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Method 1 : traverse pairs (a+b = b+a) TC : O(N^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}


// Method 2 : Using hashing but do it on the way . (Important) TC : O(N) to O(N^2), SC : (N)
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    
    unordered_map<int,int> uom;

    for(int i=0;i<n;i++){
        int requiredElement = target-nums[i];
        if(uom.count(requiredElement) == 1){
            // target found
            ans.push_back(i);
            ans.push_back(uom[requiredElement]);
            return ans;
        }else{
            uom.insert(make_pair(nums[i],i));
        }
    }
    return ans;
}


// Method 2 : Hashing
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    
    unordered_map<int,int> uom;
    for(int i=0;i<n;i++){
        uom.insert(make_pair(nums[i],i));
    }

    for(int i=0;i<n;i++){
        int requiredElement = target-nums[i];
        if(uom.count(requiredElement) == 1 && uom[requiredElement] != i){
            // target found
            ans.push_back(i);
            ans.push_back(uom[requiredElement]);
            return ans;
        }
    }
    return ans;
}


// Method 3 : Two Pointer -> Sorted array is must
bool twoSum3(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size()-1;

    while(left < right){
        int currSum = nums[left] + nums[right];
        if(currSum == target){
            return true;
        }
        else if(currSum < target){
            left++;
        }else{
            right--;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,3,9,5,3,11};
    int target = 6;
    cout << twoSum3(nums,target) << endl;
    return 0;
}