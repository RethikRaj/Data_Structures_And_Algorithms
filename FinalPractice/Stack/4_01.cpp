#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOpen(char &ch){
        return ch == '(' || ch == '{' || ch == '[';
    }

    bool isMatch(char &top, char &ch){
        if(top == '(' && ch == ')'){
            return true;
        }else if(top == '{' && ch == '}'){
            return true;
        }else if(top == '[' && ch == ']'){
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i < s.size(); i++){
            char ch = s[i];
            bool isOpenBracket = isOpen(ch);
            if(isOpenBracket){
                st.push(ch);
            }
            else{ // closing bracket

                // Stack is empty => return false
                if(st.empty()){
                    return false;
                }
                // Stack is not empty => We can access s.top()
                char top = st.top();

                bool isBracketsMatch = isMatch(top, ch);
                if(isBracketsMatch){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};