#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Method1 ; best
class Solution {
public:
    bool canWeMakeMbouqetsWithDdays(vector<int>& bloomDay,int m, int k,int day){
        int numberOfBuoqetsThatCanBeMade = 0;
        int count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                // flower bloomed
                count += 1;
            }else{
                // flower not bloomed
                count = 0;
            }

            // Check whether we got k adjacent
            if(count == k){
                numberOfBuoqetsThatCanBeMade++;
                // reset count
                count = 0;
                if(numberOfBuoqetsThatCanBeMade == m){
                    break;
                }
            }
        }
        return numberOfBuoqetsThatCanBeMade == m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long int condition = (long long int)m * (long long int)k;
        if(condition > bloomDay.size()){
            return -1;
        }


        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = 0;
        int mid = start + ((end-start)>>1);

        while(start <= end){
            if(canWeMakeMbouqetsWithDdays(bloomDay,m,k,mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
            mid = start + ((end-start)>>1);
        }
        return ans;
    }
};

// Method 2 :
int minDays(vector<int>& bloomDay, int m, int k) {
    int maxBloomDay = INT_MIN;
    int n = bloomDay.size();
    for(int i=0;i<bloomDay.size();i++){
        maxBloomDay = max(maxBloomDay,bloomDay[i]);
    }

    int s = 0;
    int e = maxBloomDay;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s <= e){
        // Predicate getting
        int count = 0;
        for(int i=0;i<=n-k; ){
            int j = i;
            while(j < i+k && mid-bloomDay[j] >= 0){
                j++;
            }
            if(j == i+k){
                count++;
                i = j;
            }
            else if(j < i+k){
                i = j+1;
            }
        }

        // predicate checking
        if(count >= m){
            ans = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> bloomDay = {1,10,2,9,3,8,4,7,5,6};
    //cout << predicateFunction(bloomDay,9,2) << endl;
}