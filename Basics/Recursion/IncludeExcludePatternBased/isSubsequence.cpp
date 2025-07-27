#include<iostream>
#include<vector>

using namespace std;

// Method 2 : TLE
void subsequenceUtil(string &str1,string& str2,int index,string output,bool& ans){
    // base case
    if(index == str1.length()){
        // We get subseqience(output) at base case => store and return
        if(output.compare(str2)==0){
            ans = true;
        }
        return;
    }
    // 1 case me solve and remaining recursion
    char ch = str1[index];
    // Include
    subsequenceUtil(str1,str2,index+1,output+ch,ans);
    // Exclude
    subsequenceUtil(str1,str2,index+1,output,ans);
}

bool isSubsequence(string s, string t) {
    //vector<string> ans;
    bool ans = false;
    subsequenceUtil(t,s,0,"",ans);
    return ans;
}


// Method 1 : TLE

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

bool isSubsequence(string s, string t) {
    vector<string> ans;
    storeSubsequences(t,0,"",ans);
    for(int i=0;i<ans.size();i++){
        if(ans[i].compare(s) == 0){
            return true;
        }
    }
    return false;
}