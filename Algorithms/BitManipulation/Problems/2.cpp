#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prefixXORApproach(vector<int>& arr, vector<vector<int>>& queries){
        vector<int> prefixXor;
        int xorAns = 0;
        for(int i=0;i<arr.size();i++){
            xorAns = xorAns ^ arr[i];
            prefixXor.push_back(xorAns);
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];

            if(left == 0){
                ans.push_back(prefixXor[right]);
            }else{
                ans.push_back(prefixXor[right] ^ prefixXor[left-1]);
            }
        }
        return ans;

    }

    vector<int> bruteForce(vector<int>& arr, vector<vector<int>>& queries){
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int xorAns = 0;
            for(int i=left;i<=right;i++){
                xorAns = xorAns ^ arr[i];
            }
            ans.push_back(xorAns);
        }
        return ans;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //return bruteForce(arr,queries);

        return prefixXORApproach(arr,queries);
    }
};