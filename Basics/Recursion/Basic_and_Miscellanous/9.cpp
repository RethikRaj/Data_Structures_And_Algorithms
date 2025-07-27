#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Method2 :  TLE (68/166) cases passed
int countGoodNumbers(long long n) { 
    long long int count = 1;
    int round = pow(10,9)+7;
    for(int i=0;i<n;i++){
        if((i&1) == 0){
            count = count*5;
        }else{
            count *=4;
        }
        if(count >= round){
            count = count%round;
        }
    }
    return count;
}

// Method1: Using backtrack but problem is exponential time complexity which leads to TLE
class Solution {
public:
    vector<int> even = {0,2,4,6,8};
    vector<int> prime = {2,3,5,7};
    void solve(string& ans,long long index,long long n,int &count){
        // Base case
        if(index >= n){
            count++;
            return;
        }
        // 1 case me solve remaining recursion will handle
        if((index&1) == 0){
            for(int i=0;i<even.size();i++){
                char ch = even[i]+'0';
                ans.push_back(ch);
                solve(ans,index+1,n,count);
                // Backtrack
                ans.pop_back();
            }
        }else{
            for(int i=0;i<prime.size();i++){
                char ch = prime[i]+'0';
                ans.push_back(ch);
                solve(ans,index+1,n,count);
                ans.pop_back();
            }
        }
    }

    int countGoodNumbers(long long n) {
        string ans = "";
        long long index = 0;
        int count = 0;
        solve(ans,index,n,count);
        return count;
    }
};