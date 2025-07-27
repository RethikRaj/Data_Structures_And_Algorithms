#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode{
    public:
        char value;
        unordered_map<int,TrieNode*> children;
        bool isTerminal;


        TrieNode(char val){
            this->value = val;
            this->isTerminal = false;
        }
};

void insertIntoTrie(TrieNode* root,string &word,int index){
    // base case
    if(index == word.length()){
        root->isTerminal = true;
        return;
    }

    // 1 case me solve remaining recursion will handle
    char ch = word[index];
    if((root->children).find(ch) != (root->children).end()){
        // present
        insertIntoTrie((root->children)[ch],word,index+1);
    }
    else{
        // absent
        // new trie node
        TrieNode* newNode = new TrieNode(ch);
        // Link
        (root->children)[ch] = newNode;
        // recursion
        insertIntoTrie(newNode,word,index+1);
    }
}

bool search(TrieNode* root,string &word,int index){
    // base case
    if(index == word.length()){
        return root->isTerminal; 
    }

    // 1 case me solve remaining recursion will handle
    char ch = word[index];

    if((root->children).find(ch) != (root->children).end()){
        // present
        return search((root->children)[ch],word,index+1);
    }else{
        // absent
        return false;
    }
}

// Logic : if word present make terminal false
void deleteWord(TrieNode* root,string &word,int index){
    // base case
    if(index == word.size()){
        root->isTerminal = false;
        return;
    }

    // 1 case me solve remaining recursion
    // 1 case
    char ch = word[index];
    TrieNode* child;
    
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }else{
        // absent
        return;
    }
    // recursion
    deleteWord(child,word,index+1);
}


int main(){
    TrieNode* root = new TrieNode('-');
    vector<string> words = {"cat","cover","code","take","top","car","care","tip"};
    for(int i=0;i<words.size();i++){
        insertIntoTrie(root,words[i],0);
    }

    // seaching
    string toSearchWord = "car";
    cout <<  toSearchWord << " : " <<search(root,toSearchWord,0) << endl;
    toSearchWord = "care";
    cout <<  toSearchWord << " : " <<search(root,toSearchWord,0) << endl;
    toSearchWord = "tie";
    cout <<  toSearchWord << " : " <<search(root,toSearchWord,0) << endl;
    toSearchWord = "chipotle";
    cout <<  toSearchWord << " : " <<search(root,toSearchWord,0) << endl;

    // deleting
    string toDeleteWord = "car";
    toSearchWord = "car";
    cout <<  toSearchWord << " : " <<search(root,toSearchWord,0) << endl;

    
    


    return 0;
}

