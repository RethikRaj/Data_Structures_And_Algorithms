#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool getTimeTaken(vector<int>& piles,int k,int h){
    int timeTaken = 0;
    for(int i=0;i<piles.size();i++){
        // method 1 
        // if(piles[i] % k == 0){
        //     timeTaken += piles[i]/k;
        // }else{
        //     timeTaken += piles[i]/k + 1;
        // }

        // method 2 :
        timeTaken += ceil((double)piles[i]/k);
        
        // optimiisation
        if(timeTaken > h){
            break;
        }
    }

    return timeTaken <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    // int maxBananas = INT_MIN;
    // for(int i=0;i<piles.size();i++){
    //     maxBananas = max(piles[i],maxBananas);
    // }

    int maxBananas = *max_element(piles.begin(), piles.end());

    int s = 1;
    int e = maxBananas;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s <= e){
        if(getTimeTaken(piles,mid,h)){ //predicate
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    return 0;
    
}