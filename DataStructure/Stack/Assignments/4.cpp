#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution{
    string reverseEqn1(string s){
        stack<char> st;
        
        int num = 0;
        // storing in stack
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
        }
        
        string ans = "";
        stack<char> temp;
        while(!st.empty()){
            char ch = st.top();
            if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
                // if ch is not a operator , then push it into another stack
                temp.push(ch);
                st.pop();
            }else{
                // if ch is an operator, the pop from the temp stack => why doing this push & pop => because i need numerical values in same order => 1st stack reverse => 2nd stack reverse => same order
                while(!temp.empty()){
                    ans.push_back(temp.top());
                    temp.pop();
                }
                // add operator to the ans
                ans.push_back(st.top());
                st.pop();
            }
        }
        // for last operand
        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }

    string reverseEqn2(string s){
        stack<string> st;

        string temp = "";
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
                temp.push_back(ch);
            }else{
                st.push(temp);
                temp = "";
                // convert the operator(char) to string and then push
                st.push(string(1,ch));
            }
        }
        // Last operand
        st.push(temp);

        // make ans
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};