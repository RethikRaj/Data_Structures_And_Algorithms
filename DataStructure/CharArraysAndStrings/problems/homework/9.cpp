#include <iostream>
#include <vector>

using namespace std;

// Method 3:
int strStr(string haystack, string needle) {
    int n = haystack.length();
    int k = needle.length();
    if(k>n){
        return -1;
    }

    for(int i=0;i<n-k+1;i++){
        int p1 = i; // points to haystack
        int p2 = 0; // points to needle
        while(p2 < k){ // checking whether k characters same
            if(haystack[p1] != needle[p2]){
                break;
            }
            p1++;
            p2++;
        }
        if(p2 == k){ // all k character matched from haystack[i] => starting index = i => return i
            return i;
        }
    }
    return -1;
}

// Method 2:
int strStr(string haystack, string needle) {
    int n = haystack.length();
    int k = needle.length();
    if(k>n){
        return -1;
    }

    for(int i=0;i<n-k+1;i++){
        if(haystack.substr(i,k).compare(needle) == 0){
            return i;
        }
    }
    return -1;
}


// Method 1
int strStr(string haystack, string needle) {
    return haystack.find(needle);
}