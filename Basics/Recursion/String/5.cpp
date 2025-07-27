#include <iostream>

using namespace std;


// method 2:
class Solution {
public:
    void solve(string &s,string &part){

        // 1 case -> find part in s
        int found = s.find(part);
        if(found != string::npos){
            // part string has been found
            // remove it -> How to remove -> concatenate the left(before found index) and right(after found index)
            string leftPart = s.substr(0,found);
            string rightPart = s.substr(found+part.size(),s.size());
            s = leftPart + rightPart; 
            // recursion
            solve(s,part);
        }else{
            // part is not found in s -> base case
            return;
        }
    }

    string removeOccurrences(string s, string part) {
        solve(s,part);
        return s;
    }
};



// method 1 :
class Solution {
public:
    void solve(string &s,string &part,int start,int end){
        // base case
        if(start < 0 || end >= s.length()){
            return;
        }

        // 1 case->1 window check
        int i=start,j=0;
        while(i <= end){
            if(s[i] != part[j]){
                // break
                break;
            }
            i++;
            j++;
        }
        if(i > end){
            // matched->remove
            s.erase(start,part.length());
            solve(s,part,0,part.length()-1);
        }else{
            solve(s,part,start+1,end+1);
        }
    }

    string removeOccurrences(string s, string part) {
        int i = 0;
        int j = part.length()-1;

        solve(s,part,i,j);

        return s;
    }
};