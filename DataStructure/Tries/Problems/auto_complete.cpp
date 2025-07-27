#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode{
    public:
        int val;
        unordered_map<int,TrieNode*> children;
        bool isTerminal;
    
        TrieNode(int val){
            this->val = val;
            this->isTerminal = false;
        }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        int index = 0;
        TrieNode* ptr = root;

        while(index < word.length()){
            char ch = word[index];
            if((ptr->children).find(ch) != (ptr->children).end()){
                ptr = (ptr->children)[ch];
            }
            else{
                // not found;
                TrieNode* newNode = new TrieNode(ch);
                (ptr->children)[ch] = newNode;
                ptr = newNode;
            }
            index++;
        }
        ptr->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* ptr = root;
        int index = 0;

        while(index < word.length()){
            char ch = word[index];
            if((ptr->children).find(ch) != (ptr->children).end()){
                ptr = (ptr->children)[ch];
            }
            else{
                // not found;
                return false;
            }
            index++;
        }

        return ptr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        int index = 0;

        while(index < prefix.length()){
            char ch = prefix[index];
            if((ptr->children).find(ch) != (ptr->children).end()){
                ptr = (ptr->children)[ch];
            }
            else{
                // not found;
                return false;
            }
            index++;
        }

        return true;
    }

    void suggestionsHelper(TrieNode* ptr,vector<string> &words,string &word){
        if(ptr->isTerminal == true){
            words.push_back(word);
            // IMPPPPPP
            // do not return here
        }

        // 1 case me solve remaining recursion will handle
        for(auto it : ptr->children){
            char ch = it.first;
            TrieNode* child = it.second;
            word.push_back(ch);
            suggestionsHelper((ptr->children)[ch],words,word);
            word.pop_back();
        }
    }

    vector<string> suggestions(string prefix){
        TrieNode* ptr = root;
        int index = 0;
        vector<string> words;

        while(index < prefix.size()){
            char ch = prefix[index];
            if((ptr->children).find(ch) != ptr->children.end()){
                ptr = ptr->children[ch];
            }else{
                // prefix not exist -> no suggestions
                return words;
            }
            index++;
        }

        // now ptr points to last char of prefix in trie
        string word = "";
        suggestionsHelper(ptr,words,word);
        // add prefix to all word in words
        for(int i=0;i<words.size();i++){
            words[i] = prefix + words[i];
        }
        return words;
    }
};




int main(){
    Trie* trie = new Trie();

    trie->insert("babbar");
    trie->insert("babb");
    trie->insert("baby");
    trie->insert("baba");
    trie->insert("babrt");
    trie->insert("babret");
    trie->insert("babrz");

    string prefix = "bab";

    vector<string> suggestions = trie->suggestions(prefix);

    for(int i=0;i<suggestions.size();i++){
        cout << suggestions[i] << " ";
    }
    cout << endl;

    return 0;
}

