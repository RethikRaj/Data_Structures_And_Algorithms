#include <bits/stdc++.h>
using namespace std;


// Solution 1: Brute Force : TC: O(n^2), SC : O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        // freqMap
        // person i -> <how_many_person_does_personI_know, how_many_persons_know_person_i;
        unordered_map<int, pair<int, int>> mp;
        
        for(int i=0;i<n;i++){
            mp[i] = make_pair(0, 0);
        }
        
        for(int i=0; i < n;i++){
            for(int j=0; j < n;j++){
                if(mat[i][j] == 1){
                    mp[i].first += 1;
                    mp[j].second += 1;
                }
            }
        }
        
        for(int i = 0;i < n ;i++){
            if(mp[i].first == 1 && mp[i].second == n){
                return i;
            }
        }
        return -1;
        
    }
};