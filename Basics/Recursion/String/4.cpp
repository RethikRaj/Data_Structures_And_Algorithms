#include<iostream>
using namespace std;

bool isPalindrome(string& s,int start,int end){
    // Base case
    if(start > end){
        return true;
    }
    // 1 case me solve
    if(s[start] != s[end]){
        return false;
    }
    // Remaining recursion will handle
    return isPalindrome(s,start+1,end-1);
}