#include <iostream>

using namespace std;

string removeDuplicates(string s) {
    int len = s.length();
    string ans = "";

    int index = 0;
    while(index < len){
        char currChar = s[index];
        // Special case
        if(ans.empty()){
            ans.push_back(currChar);   
        }
        else if(ans.back() == currChar){
            ans.pop_back();
        }else if(ans.back() != currChar){
            ans.push_back(currChar);
        }
        index++;
    }
    return ans;
}