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
};
