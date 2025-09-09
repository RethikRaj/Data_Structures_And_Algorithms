#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPlaceCows(vector<int> &stalls, int C, int mid){
        
        int prevCowPosition = stalls[0]; // place 1st cow at 0th stall
            
        int currCow = 2;
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - prevCowPosition >= mid){
                // Place the currCow
                prevCowPosition = stalls[i];
                
                currCow += 1;
                
                // if already placed C cows , then return true
                if(currCow > C){
                    return true;
                }
            }
        }
        
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int C) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[stalls.size() - 1] - stalls[0];
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(canPlaceCows(stalls, C, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
};