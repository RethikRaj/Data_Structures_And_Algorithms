#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
  public:
    void solve(string &str,string &output,int index,unordered_set<string> &subsequences){
        // Base case
        if(index >= str.size()){
            subsequences.insert(output);
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        // Include
        output.push_back(str[index]);
        solve(str,output,index+1,subsequences);
        output.pop_back();
        
        // Exclude
        solve(str,output,index+1,subsequences);
    }
    
    string betterString(string str1, string str2) {
        unordered_set<string> subsequences;
        string output = "";
        int index = 0;
        solve(str1,output,index,subsequences);
        int count1 = subsequences.size();
        
        subsequences.clear();
        output = "";
        solve(str2,output,index,subsequences);
        int count2 = subsequences.size();
       
        
        if(count1 >= count2){
            return str1;
        }else{
            return str2;
        }
    }
};