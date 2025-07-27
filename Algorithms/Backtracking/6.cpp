#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(string &digits,vector<string> &ans,unordered_map<char,string> &mapping,string &combination,int i){
        // Base case
        if(i >= digits.length()){
            if(combination.length() > 0){
                ans.push_back(combination);
            }
            return;
        }

        // 1 case me solve remaining recursion handle
        char digit = digits[i];
        string mappedString = mapping[digit];

        for(char ch: mappedString){
            combination.push_back(ch);
            // recursion call
            solve(digits,ans,mapping,combination,i+1);
            // Backtracking
            combination.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        
        string combination = "";
        int i=0;
        solve(digits,ans,mapping,combination,i);
        return ans;

    }
};
