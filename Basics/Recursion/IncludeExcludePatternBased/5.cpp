#include <bits/stdc++.h> 

using namespace std;

void solve(string& str,int index,vector<string>& ans){
    // Base case
    if(index >= str.size()){
        ans.push_back(str);
        return;
    }
    // 1 case me solve remaining recursion will handle
    if(str[index] == '?'){
        str[index] = '0';
        solve(str,index+1,ans);
        str[index] = '1';
        solve(str,index+1,ans);
        str[index] = '?';
    }else{
        solve(str,index+1,ans);
    }
}

vector<string> binaryStrings(string &str) {
    vector<string> ans;
    int index = 0;
    solve(str,index,ans);
    return ans;
}