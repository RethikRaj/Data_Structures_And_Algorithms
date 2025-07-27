#include <iostream>
#include <vector>

using namespace std;

void solve(string& output,int index,int n,vector<string> &ans){
    // Base case
    if(index >= n){
        cout << output << " ";
        ans.push_back(output);
        return;
    }
    // 1 case me solve remaining recursion 
    if(output.size() == 0 || output[output.size()-1] == '0'){
        output.push_back('0');
        solve(output,index+1,n,ans);
        output.pop_back();
        output.push_back('1');
        solve(output,index+1,n,ans);
        output.pop_back();
    }else{
        output.push_back('0');
        solve(output,index+1,n,ans);
        output.pop_back();
    }
}


vector<string> generateString(int N) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(output,index,N,ans);
    return ans;
}

int main(){
    generateString(4);
}