#include <iostream>
#include <vector>

using namespace std;

// Method 2 : (Best)
bool isIsoMorphic(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    int n = s.length();
    vector<char> hashFromStoT(256,'\0');
    vector<char> hashFromTtoS(256,'\0');

    for(int i=0;i<n;i++){
        if(hashFromStoT[s[i]] == '\0'){ // first time mapping of char s[i] to char t[i]
            hashFromStoT[s[i]] = t[i];
        }
        if(hashFromTtoS[t[i]] == '\0'){ // first time mapping of char t[i] to char s[i]
            hashFromTtoS[t[i]] = s[i];
        }
        if(hashFromStoT[s[i]] != t[i] || hashFromTtoS[t[i]] != s[i]){ // second time is same char not mapped then false
            return false;
        }
    }
    return true;
}



// Method 1
bool utility(string s,string t){
    int n = s.length();
    vector<vector<int>> charactersIndexes(256);
    for(int i=0;i<n;i++){
        char ch = s[i];
        charactersIndexes[ch].push_back(i);
    }

    for(int i=0;i<n;i++){
        char ch1 = s[i];
        char ch2 = t[i];

        // checking whether for all occurences of ch1 in s whther it maps with ch2 in t;
        vector<int>& characterIndexes = charactersIndexes[ch1];
        for(int index : characterIndexes){
            if(t[index] != ch2){
                return false;
            }
        }
    }
    return true;
}

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    
    // s must be isomorphic to t and t must be isomorphic to s;
    return utility(s,t) && utility(t,s);
}