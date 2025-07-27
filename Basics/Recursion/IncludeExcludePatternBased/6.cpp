#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(string& output,int numberOfOpenBrackets,int numberOfCloseBrackets,vector<string> &ans,int n){
        // base case
        if(numberOfOpenBrackets == n && numberOfCloseBrackets==n){
            ans.push_back(output);
            return;
        }

        // 1 case me solve remaining recursion.
        if(numberOfOpenBrackets > numberOfCloseBrackets){
            if(numberOfOpenBrackets != n){
                output.push_back('(');
                solve(output,numberOfOpenBrackets+1,numberOfCloseBrackets,ans,n);
                output.pop_back();
            }
            output.push_back(')');
            solve(output,numberOfOpenBrackets,numberOfCloseBrackets+1,ans,n);
            output.pop_back();
        }else{
            output.push_back('(');
            solve(output,numberOfOpenBrackets+1,numberOfCloseBrackets,ans,n);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        int numberOfOpenBrackets = 0;
        int numberOfCloseBrackets = 0;
        solve(output,numberOfOpenBrackets,numberOfCloseBrackets,ans,n);
        return ans;
    }
};