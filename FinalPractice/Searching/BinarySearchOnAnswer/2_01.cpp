#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bruteForce(int n){
        int rowsCount = 0;
        while(n - (rowsCount + 1) >= 0){
            rowsCount += 1;
            n -= rowsCount;
        }
        return rowsCount;
    }

    int optimizedBinarySearchApproach(int n){
        long long int low = 1;
        long long int high = n;
        long long int ans = -1;
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int numberOfCoinsNeededToMakeMidCompleteRows = ((mid)*(mid+1))/2;
            if(numberOfCoinsNeededToMakeMidCompleteRows <= n){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return (int)ans;
    }

    int mathsApproach(int n){
        double _n = n;
        double ans = (-1 + sqrt(1 + 8*_n))/2;
        
        return (int)ans;
    }

    int arrangeCoins(int n) {
        // Brute Force 
        // return bruteForce(n);

        // optimized binary search
        return optimizedBinarySearchApproach(n);
        

        // My approach
        // return mathsApproach(n);
    }
};