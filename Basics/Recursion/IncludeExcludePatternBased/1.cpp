#include<iostream>
#include<vector>

using namespace std;

void storeSubsequences(string &str,int index,string output,vector<string>& ans){
    // base case
    if(index == str.length()){
        // We get subseqience(output) at base case => store and return
        ans.push_back(output);
        return;
    }
    // 1 case me solve and remaining recursion
    char ch = str[index];
    // Include
    storeSubsequences(str,index+1,output+ch,ans);
    // Exclude
    storeSubsequences(str,index+1,output,ans);
}

int main(){
    string s = "abc";
    vector<string> ans;
    string output = "";
    int index = 0;
    storeSubsequences(s,index,output,ans);
}