#include <iostream>

using namespace std;

void convertToLowerCase(string& s){
    int length = s.length();
    for(int i=0;i<length;i++){
        char ch = s[i];
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A' + 'a';
        }
        s[i] = ch;
    }
}

bool isPalindrome(string s) {
    convertToLowerCase(s);
    int length = s.length();
    int start = 0;
    int end = length-1;
    while(start <= end){
        if((s[start] < 'a' || s[start] > 'z') && (s[start] < '0' || s[start] > '9')){
            start++;
            continue;
        }
        if((s[end] < 'a' || s[end] > 'z') && (s[end] < '0' || s[end] > '9')){
            end--;
            continue;
        }

        if(s[start] != s[end]){
            return false;
        }

        start++;
        end--;
    }
    return true;
}