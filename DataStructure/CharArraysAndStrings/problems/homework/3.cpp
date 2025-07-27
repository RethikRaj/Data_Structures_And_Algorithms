#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// TC : O(minLen*n) SC:O(1)
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    int minLen = INT_MAX;
    for(int i=0;i<n;i++){
        if(strs[i].length() < minLen){
            minLen = strs[i].length();
        }
    }

    int index = 0;
    while(index < minLen){
        // Checking whether all strings in strs have same indexTH charcacter
        int j = 0; // to loop through strs
        while(j < n-1){
            if(strs[j][index] != strs[j+1][index]){
                return strs[0].substr(0,index);
            }
            j++;
        }
        index++;
    }
    return strs[0].substr(0,index);
}
