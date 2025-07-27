#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Method 2 : Normalise string and pattern and compare
string normalise(string s){
    // Create mapping
    unordered_map<char,char> mapping;
    char start = 'a';
    for(int i=0;i<s.length();i++){
        if(mapping.find(s[i]) == mapping.end()){
            // First time occurence of char s[i] => store in map
            mapping[s[i]] = start;
            start++;
        }
    }

    // Normalise the string
    for(int i=0;i<s.length();i++){
        s[i] = mapping[s[i]];
    }
    return s;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n = words.size();
    string normalizedPattern = normalise(pattern);
    vector<string> ans;
    for(int i=0;i<n;i++){
        // Normalise word
        string normalizedWord = normalise(words[i]);
        // Check with normalised pattern
        if(normalizedWord.compare(normalizedPattern) == 0){
            ans.push_back(words[i]);
        }
    }
    return ans;
}





// method 1 : isomorphic check and add
bool isIsomorphicString(string s,string t){
    // if(s.length() != t.length()){ // not needed since in constraints its given that it will equal by default.
    //     return false;
    // }
    int len = s.length();
    vector<char> hashFromStoT(256,'\0');
    vector<char> hashFromTtoS(256,'\0');

    for(int i=0;i<len;i++){
        if(hashFromStoT[s[i]] == '\0'){
            hashFromStoT[s[i]] = t[i];
        }
        if(hashFromTtoS[t[i]] == '\0'){
            hashFromTtoS[t[i]] = s[i];
        }
        if(hashFromStoT[s[i]] != t[i] || hashFromTtoS[t[i]] != s[i]){
            return false;
        }
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    int n = words.size();
    vector<string> ans;
    for(int i=0;i<n;i++){
        if(isIsomorphicString(words[i],pattern)){
            ans.push_back(words[i]);
        }
    }
    return ans;
}