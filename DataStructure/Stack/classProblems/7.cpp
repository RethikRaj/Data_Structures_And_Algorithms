#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            // ch may be open or close bracket
            if(ch == '(' || ch == '{' || ch == '[' ){
                // ch is open bracket => no decision now => just push
                st.push(ch);
            }else{
                // ch is close bracket => need to check top of the stack 
                // But before checking top always check empty
                if(ch == ')' && !st.empty() && st.top() == '('){
                    // Brackets match -> Cancel out
                    st.pop();
                }else if(ch == '}' && !st.empty() && st.top() == '{'){
                    // Brackets match -> Cancel out
                    st.pop();
                }else if(ch == ']' && !st.empty() && st.top() == '['){
                    // Brackets match -> Cancel out
                    st.pop();
                }else{
                    // Brackets didnt match or st is empty
                    return false;
                    // instead of returning false here if i push ch into stack then after coming out of this loop staclk contains all unbalanaced paranthesis => This is an imp idea for questions like minimum bracket reversal etc...
                }
            }
        }    

        // out of loop => check stack if empty then true else false
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }

    // logic same just a diff way of coding
    bool isValid2(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    // Stack is not empty => s.top() is available
                    if(ch == ')' && st.top() == '('){
                        st.pop();
                    }
                    else if(ch == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '['){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }

};