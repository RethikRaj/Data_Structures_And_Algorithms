#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Method 2 : LB solution => swap method





// Method 1 : My solution

// Method 1.1 : Using set to solve duplicacy of permutation
void solve(string &S,string permutedString,unordered_set<string> &ans,vector<bool> &characterVisited){
    // base case
    if(permutedString.length() == S.length()){
        ans.insert(permutedString);
        return;
    }
    //1 case me solve , remaining recursion
    //1 case -> traversing through each character
    for(int i=0;i<S.length();i++){
        if(characterVisited[i] == false){
            characterVisited[i] = true;
            solve(S,permutedString+S[i],ans,characterVisited);
            characterVisited[i] = false;
        }
    }
}
        
vector<string>find_permutation(string S){
    // To store all unique permutations
    unordered_set<string> ans;
    // To store each permutedString
    string permutedString = "";
    vector<bool> characterVisited(S.length(),false);
    solve(S,permutedString,ans,characterVisited);
    
    // Since vector must be returned => copy set into vector
    vector<string> result(ans.begin(),ans.end());
    return result;
}

// method 1.2 : Using map to solve duplicacy of permutation

void solve(string& S,vector<string> &ans,string permutation,unordered_map<char,int> &mapping){
    if(permutation.length() == S.length()){
        ans.push_back(permutation);
        return;
    }

    unordered_map<char,int>::iterator it = mapping.begin();
    while(it != mapping.end()){
        char key = (*it).first;
        if(mapping[key] != 0){
            mapping[key] -= 1;
            permutation.push_back(key);
            solve(S,ans,permutation,mapping);
            permutation.pop_back();
            mapping[key] += 1;
        }
        // Dont forgget
        it++;
    }
    
}
    
vector<string>find_permutation(string S){
    unordered_map<char,int> mapping;
    for(int i=0;i<S.length();i++){
        mapping[S[i]] += 1;
    }

    vector<string> ans;
    string permutation;
    solve(S,ans,permutation,mapping);

    return ans;
}



