#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isItPossibleWithSspeed(int s, vector<int>& piles, int h){
        long long int timeTaken = 0;

        for(int i=0; i < piles.size();i++){
            timeTaken += ceil((double)piles[i] / s);
        }

        return timeTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int pile : piles){
            maxi = max(maxi, pile);
        }

        int low = 1;
        int high = maxi;
        int ans = -1;
        while( low <= high){
            int mid = low + (high - low)/2;

            bool isItPossible =  isItPossibleWithSspeed(mid, piles, h);

            if(isItPossible){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};