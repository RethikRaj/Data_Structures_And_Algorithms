#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
        
    if(s.length() != t.length()){
        return false;
    }

    vector<int> freq(26,0); // here 26 works because only alphabets i considered // or use freq[256] then freq[s[i]] will be used while accessing 
    
    int n = s.length();

    for(int i=0;i<n;i++){
        freq[s[i]-'a'] += 1;
    }

    for(int i=0;i<n;i++){
        if(freq[t[i]-'a'] == 0){
            return false;
        }
        freq[t[i]-'a'] -= 1;
    }
    return true;
}