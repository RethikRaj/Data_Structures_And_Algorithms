#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getPerfectSquares(int n,vector<int> &perfectSquares){
        int num = 1;
        while(num*num <= n){
            perfectSquares.push_back(num*num);
            num += 1;
        }
    }

    void solve(int n,vector<int> &perfectSquares,int count,int &minCount){
        // base case
        if(n == 0){
            minCount = min(minCount,count);
            return;
        }

        // 1 case me solve remaining recursion will handle
        for(int i=0;i<perfectSquares.size();i++){
            int curr = perfectSquares[i];
            if(curr <= n){
                solve(n-curr,perfectSquares,count+1,minCount);
            }else{
                continue; // or return -> since perfectSquares is sorted array
            }
        }
    }


    int numSquares(int n) {
        vector<int> perfectSquares;
        getPerfectSquares(n, perfectSquares);

        int count = 0;
        int minCount = INT_MAX;
        solve(n,perfectSquares,count,minCount);
        return minCount;
    }
};