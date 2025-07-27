#include <iostream>

using namespace std;

class Solution {
public:
    bool solve(string &s,string &p,int i,int j){
        // base case (IMPPPPPPPPPP)
        // if(j >= p.length()){
        //     if(i >= s.length()){
        //         return true;
        //     }else{
        //         return false;
        //     }
        // }

        // if(i >= s.length()){
        //     if(j >= p.length()){
        //         return true;
        //     }else{
        //         for(int z = j ;z < p.length();z++){
        //             if(p[z] != '*'){
        //                 return false;
        //             }
        //         }
        //         return true;
        //     }
        // }

        // base case (Method 2)
        if(i >= s.length() && j >= p.length()){
            return true;
        }
        else if(i >= s.length() && j < p.length()){
            for(int z=j;z<p.length();z++){
                if(p[z] != '*'){
                    return false;
                }
            }
            return true;
        }else if(j >= p.length() && i < s.length()){
            return false;
        }   

        // 1 case me solve remaining recursion will handle
        if(p[j] == '?'){
            return solve(s,p,i+1,j+1);
        }else if (p[j] == '*'){
            // Include s[i] in *  => Let * consume one character
            bool includeRecAns = solve(s,p,i+1,j);
            // exclude s[i] in * => Treat * as null or empty
            bool excludeRecAns = solve(s,p,i,j+1);

            return includeRecAns || excludeRecAns;
        }else{
            // p[j] is just a character
            if(s[i] != p[j]){
                return false;
            }else{
                return solve(s,p,i+1,j+1);
            }
        }
    }

    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        bool ans = solve(s,p,i,j);
        return ans;
    }
};