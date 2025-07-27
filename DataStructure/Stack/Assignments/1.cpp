#include <iostream>
#include <stack>

using namespace std;

class Solution{
    public:
        // M1=> Based on my dry run
        int countRev(string s){
            stack<char> st;
            int count = 0;
            
            for(int i=0;i<s.size();i++){
                char ch = s[i];//incoming char
                
                // if ch is open bracket 
                if(ch == '{'){
                    st.push(ch);
                }else{
                    // ch is close bracket
                    if(st.empty()){
                        count++;
                        // Push reverse(close -> open) into stack
                        st.push('{');
                    }else if(st.top() == '{'){
                        st.pop();
                    }
                }
            }
            
            int noOfOpen = 0;
            while(!st.empty()){
                noOfOpen++;
                st.pop();
            }
            
            if((noOfOpen&1) == 0){
                count += (noOfOpen/2);
                return count;
            }else{
                return -1;
            }
        }

        // M2 => Based on valid paranthesis approach

        int countRev2(string s){
            if((s.size()&1)==1){
                // odd length string
                return -1;
            }
            
            stack<char> st;
            int count = 0;
            
            // Remove valid parenthesis
            for(int i=0;i<s.size();i++){
                char ch = s[i];
                if(ch == '{'){
                    st.push(ch);
                }else{
                    if(!st.empty() && st.top() =='{'){
                        st.pop();
                    }else{
                        st.push(ch);
                    }
                }
            }
            
            // Now stack contains only unbalanced paranthesis => Try to make pairs of valid paranthesis.
            while(!st.empty()){
                char a = st.top();st.pop();
                char b = st.top();st.pop();
                
                if(a==b){
                    count += 1;
                }else{
                    count += 2;
                }
            }
            return count;
        }
};
