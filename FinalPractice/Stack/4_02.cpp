#include <bits/stdc++.h>
using namespace std;


// s -> string which is balanced and contains only ( , ), +, -, *, /, alphabets or digits
class Solution {
  public:
    bool isOperator(char ch){
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    
    bool isOpen(char ch){
        return ch == '(';
    }
    
    bool isClosed(char ch){
        return ch == ')';
    }

    int countRedundantBrackets(string &s) {
        stack<char> st;
        int numberOfRedundantBrackets = 0;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if(isOperator(ch) || isOpen(ch)){
                st.push(ch);
            }
            else if(isClosed(ch)){
                int operatorCount = 0;
                
                while(!st.empty() && st.top() != '('){
                    if(isOperator(st.top())){
                        operatorCount++;
                    }
                    st.pop();
                }
                // st.top() -> '('
                if(!st.empty()) {
                    st.pop(); // remove '('
                }

                if(operatorCount == 0){
                    numberOfRedundantBrackets++;
                }
            }
        }
        
        return numberOfRedundantBrackets;
    }
};
