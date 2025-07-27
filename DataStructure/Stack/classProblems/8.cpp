#include <iostream>
#include <stack>

using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;
        
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        
        // if ch is open bracket or operator => just push into stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            // ch is close bracket => search for open bracket 
            // During this search if we get an operator then it is nonredundant 
            // else it is redundant
            int operatorCount = 0;
            // Keep popping from the stack till we reach a open bracket or stack become empty.
            while(!st.empty() && st.top() != '('){
                char topEle = st.top();
                if(topEle == '+' || topEle == '-' || topEle == '*' || topEle == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();// pop the open bracket
            if(operatorCount == 0){
                return true;
            }
        }
    }
    
    return false;
}
