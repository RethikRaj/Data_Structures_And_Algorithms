#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sizeOfWord = words[0].length();

        // create a map of words
        unordered_map<string,int> um;
        for(int i=0;i<words.size();i++){
            um[words[i]]++;
        }

        vector<int> ans;
        
        // offset logic :
        // offset : 0,1,2,..,words[0].length()-1;
        for(int offset = 0;offset < sizeOfWord;offset++){
            int count = 0; // to check whether ans is reached
            unordered_map<string,int> visitedStrings;

            for(int i=offset;i + sizeOfWord <= s.length();i = i+ sizeOfWord){
                string substr = s.substr(i,sizeOfWord);

                if(um.find(substr) == um.end()){
                    // Invalid substring
                    visitedStrings.clear();
                    count = 0;
                }
                else{// Valid substring
                    visitedStrings[substr]++;
                    count++;

                    // GAME CHANGER - removal
                    while(visitedStrings[substr] > um[substr]){
                        int index = i-((count-1)*sizeOfWord);
                        string temp = s.substr(index,sizeOfWord);
                        visitedStrings[temp]--;
                        count--;
                    }
                    // GAME CHANGER

                    // Check whether ans is achieved
                    if(count == words.size()){
                        ans.push_back(i-((count-1)*sizeOfWord));
                    }
                }
            }
        }
        return ans;
    }
};


// 181/182 test cases passed
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int sizeOfWord = words[0].length();
        int windowSize = n*sizeOfWord;

        // create a map of words
        unordered_map<string,int> um;
        for(int i=0;i<words.size();i++){
            um[words[i]]++;
        }

        int i=0 , j = windowSize-1;
        vector<int> ans;
        unordered_map<string,int> copyum(um.begin(),um.end());
        
        while(j < s.length()){
            string word = "";
            int z = i;
            bool flag = true;
            while(z <= j+1){
                if(word.size() != 0 && word.size() % sizeOfWord == 0){
                    if(um[word] == 0){
                        // move to next window
                        flag = false;
                        break;
                    }else{
                        um[word]--;
                    }
                    word = "";
                }
                if(z < s.length())
                    word.push_back(s[z]); 
                z++;
            }

            if(flag){
                ans.push_back(i);
            }

            i++;
            j++;

            um = copyum;
        }

        return ans;
    }
};