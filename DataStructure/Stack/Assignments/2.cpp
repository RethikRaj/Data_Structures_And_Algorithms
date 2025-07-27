#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Method1 : without stack
    string method1(string &s){
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
            }else{
                ans.push_back(currChar);
            }
            index++;
        }
        return ans;
    }

    // Method2 : Using stack
    string method2(string &s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            if(!st.empty() && st.top() == curr){
                // pair up
                st.pop();
            }else{
                // stack is empty or st.top() != curr
                st.push(curr);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string removeDuplicates(string s) {
        //return method1(s);
        return method2(s);
    }
};