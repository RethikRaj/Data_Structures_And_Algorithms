#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// optimised approach using map
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int> mp;
        
        int prefixSum = 0;
        mp[0] = -1;
        int maxLength = 0;
        
        for(int i=0;i<arr.size();i++){
            prefixSum += arr[i];
            if(mp.find(prefixSum) != mp.end()){
                maxLength = max(maxLength,i-mp[prefixSum]);
            }
            else{
                mp[prefixSum] = i;
            }
        }
        return maxLength;
    }
};


// Brute Force : TC : O(n^2)
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxLength = 0;
        for(int i=0;i<arr.size();i++){
            int sum = 0;
            for(int j=i;j>=0;j--){
                sum += arr[j];
                if(sum == 0){
                    maxLength = max(maxLength,i-j+1);
                }
            }
        }
        
        return maxLength;
    }
};
