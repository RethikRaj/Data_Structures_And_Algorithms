#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,int> mapping;
    for(int i=0;i<n;i++){
        if(mapping.count(arr[i]) == 1){
            mapping[arr[i]]++;
        }else{
            mapping[arr[i]] = 1;
        }
    }

    
    unordered_set<int> occurences;
    unordered_map<int,int>::iterator it = mapping.begin();
    while(it != mapping.end()){
        int occurence = (*it).second;
        if(occurences.count(occurence) == 1){
            return false;
        }else{
            occurences.insert(occurence);
        }
        it++;
    }
    return true;;
}