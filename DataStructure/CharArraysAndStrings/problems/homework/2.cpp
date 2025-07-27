#include <iostream>

using namespace std;


bool isEnglishLetter(char& ch){
    int smallLetter = ch-'a';
    int capsLetter = ch-'A';

    if(smallLetter >=0 && smallLetter <= 25){
        return true;
    }
    else if(capsLetter >=0 && capsLetter <= 25){
        return true;
    }else{
        return false;
    }
}

string reverseOnlyLetters(string s) {
    int left = 0;
    int right = s.length()-1;

    while(left <= right){
        if(!isEnglishLetter(s[left])){
            left++;
        }else if(!isEnglishLetter(s[right])){
            right--;
        }else{
            // Both are english letters => swap
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    return s;
}