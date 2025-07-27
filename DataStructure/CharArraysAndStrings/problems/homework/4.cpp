#include <iostream>

using namespace std;

bool isVowel(char ch){
    ch = tolower(ch); // if using tolower then dont pass by reference because then original char changes
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ;
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.length()-1;
    while(left <= right){
        if(!isVowel(s[left])){
            left++;
        }else if(!isVowel(s[right])){
            right--;
        }else{
            // left and right both points to vowel => swap
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    return s;
}