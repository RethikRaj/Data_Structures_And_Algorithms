#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


// Solution : Traverse , sort , add
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        // traverse
        for(int i=0;i<strs.size();i++){
            string copy = strs[i];
            // sort
            sort(copy.begin(),copy.end());
            // insert in map
            mp[copy].push_back(strs[i]);
        }

        // make ans
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};



// TLE 
class Solution {
public:
    bool isAnagram(string &s, string &t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            if(mp[t[i]] == 0){
                return false;
            }else{
                mp[t[i]]--;
            }
        }

        return true;
    }

    vector<string> solve(vector<string>& strs,vector<bool> &visited,int index){
        string currString = strs[index];
        vector<string> anagrams;
        anagrams.push_back(currString);
        visited[index] = true;

        for(int i=index+1;i<strs.size();i++){
            if(!visited[i] && isAnagram(currString,strs[i])){
                anagrams.push_back(strs[i]);
                visited[i] = true;
            }
        }

        return anagrams;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<bool> visited(n,false);
        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(solve(strs,visited,i));
            }
        }

        return ans;
    }
};
