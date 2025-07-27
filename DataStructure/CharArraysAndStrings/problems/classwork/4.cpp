#include <iostream>

using namespace std;

bool checkPalindrome(string str,int start,int end){
    while(start <= end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.length()-1;

    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else{ // this else block is entered only once.
            // delete i and check
            bool deleteIPalin = checkPalindrome(s,i+1,j);
            // delete j and check
            bool deleteJPalin = checkPalindrome(s,i,j-1);

            return deleteIPalin || deleteJPalin;
        }
    }
    //valid palindome, without any deletion
    return true;
}
