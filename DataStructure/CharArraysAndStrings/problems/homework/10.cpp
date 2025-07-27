#include <iostream>

using namespace std;

class Solution {
public:
    bool isDigit(char ch){
        // Checking if ch is '0' to '9'
        int character = ch-'0';
        if(character >= 0 && character <= 9){
            return true;
        }
        return false;
    }

    int myAtoi(string s) {
        bool isNegative = false;
        bool isFirstCharacterFound = false;
        double ans = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            // leading whitespace and sign
            if(s[i] == ' ' && !isFirstCharacterFound){
                continue;
            }
            if(s[i] == '-' && !isFirstCharacterFound){
                isNegative = true;
                isFirstCharacterFound = true;
                continue;
            }
            if(s[i] == '+' && !isFirstCharacterFound){
                isFirstCharacterFound = true;
                continue;
            }
            

            if(isDigit(s[i])){
                isFirstCharacterFound = true;
                int character = ch-'0';
                ans = ans*10 + character;
            }else{ // not a digit => break
                break;
            }
        }

        // handling negativeness
        ans =  (isNegative) ? -1*ans : ans;

        // rounding
        if(ans >= INT_MAX){
            return INT_MAX;
        }else if(ans <= INT_MIN){
            return INT_MIN;
        }else{
            return (int)ans;
        }
    }
};

// Using recursion
class Solution {
public:
    bool isDigit(char ch){
        int character = ch-'0';
        if(character>=0 && character <= 9){
            return true;
        }

        return false;
    }

    void solve(string& s,int start,double &ans){
        // Base case -> start >= n or s[start] is not a digit
        if(start >= s.size() || !isDigit(s[start])){
            return;
        }
        // 1 case me solve remaining recursion takes care
        int character = s[start]-'0';
        cout << character << endl;
        ans = ans*10 +character;
        solve(s,start+1,ans);
    }

    int myAtoi(string s) {
        int n = s.size();
        // Ignoring whitespace
        int index = 0;
        while(index < n && s[index] == ' '){
            index++;
        }
        
        // Finding sign
        bool isNegative = false;
        if(s[index] == '-'){
            isNegative = true;
            index++;
        }else if(s[index] == '+'){
            index++;
        }


        double ans = 0;
        solve(s,index,ans);
        if(isNegative){
            ans = -1*ans;
        }
        if(ans > INT_MAX){
            return INT_MAX;
        }else if(ans < INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
};

