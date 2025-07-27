#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Method 2 : Using stl map
void createMapping(unordered_map<char,char> &mapping, string key) {
    char start = 'a';

    for(int i=0; i<key.length(); i++) {
        //if mapping is not already present , then create it 

        if(mapping.find(key[i]) == mapping.end()) {
            mapping[key[i]] = start;
            start++;
        }
    }

}

string useMapping(unordered_map<char,char> &mapping, string message) {
    string ans = "";
    for(int i=0; i<message.length(); i++) {
        char mappedCharacter = mapping[message[i]];
        ans.push_back(mappedCharacter);
    }
    return ans;
}

string decodeMessage(string key, string message) {
    //step1: create mapping
    unordered_map<char,char> mapping;
    char spaceCharacter = ' ';
    mapping[spaceCharacter] = spaceCharacter;

    createMapping(mapping, key);

    //step2: use mapping and decode msg
    string ans = useMapping(mapping, message);
    return ans;
}

// Method 1 : Using array to prepare mapping or hashTable.
string decodeMessage(string key, string message) {
    int n = key.length();

    // Preparing hash Table
    vector<char> hashTable(256,'\0');  // You can also intialise the size to 26 then you must use key[i]-'a' and message[i]-'a' (mapping concept)

    char start = 'a';
    for(int i=0;i<n;i++){
        if(key[i] == ' '){
            continue;
        }
        if(hashTable[key[i]] == '\0'){ // checking first occurence or not 
            hashTable[key[i]] = start;
            start++;
        }
    }

    // Using hash Table to decode
    string ans = "";
    for(int i=0;i<message.length();i++){
        if(message[i] == ' '){
            ans += " ";
            continue;
        }
        char decodedChar = hashTable[message[i]];
        ans += decodedChar ;
    }

    return ans;
}