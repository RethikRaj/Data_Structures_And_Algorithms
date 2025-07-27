#include <iostream>

using namespace std;


int expandAroundCentrePalin(string s,int i,int j){
    int n = s.length();
    int count = 0;
    while(i>=0 && j<n){ 
        // Expand only if s[i] == s[j];
        if(s[i] != s[j]){
            break;
        }
        else{
            count++;
            i--;
            j++;
        }
    }
    return count;
}


int countPalindromicSubstrings(string s) {
    int totalPalinSubstrCount = 0;
    int n = s.length();
    for(int center = 0;center < n;center++){
        // odd length
        int i = center;
        int j = center;
        int oddPalinSubstrCount = expandAroundCentrePalin(s,i,j);
        
        // even length
        i = center;
        j = center + 1;
        int evenPalinSubstrCount = expandAroundCentrePalin(s,i,j);
        totalPalinSubstrCount += (oddPalinSubstrCount + evenPalinSubstrCount);
    }
    return totalPalinSubstrCount;
}