#include<iostream>
using namespace std;

// Method 2 : R to L
int lastOccurenceOfACharacter(string& s,char ch,int index){
    if(index == -1){ // base case
        return -1;
    }
    // 1 case i will solve
    if(s[index] == ch){
        return index;
    }
    // Remaining recursion
    return lastOccurenceOfACharacter(s,ch,index-1);
}

// Method 1 : L to R
void lastOccurenceOfACharacter(string& s,char ch,int index,int& ans){
    if(index == s.length()){
        return;
    }
    // 1 case i will solve
    if(s[index] == ch){
        ans = index;
    }
    // Remaining recursion
    lastOccurenceOfACharacter(s,ch,index+1,ans);
}

int main(){
    string s = "zabcbdaz";
    char ch = 'z';
    // Method 1:
    // int ans = -1;
    // lastOccurenceOfACharacter(s,ch,0,ans);
    // cout << "Last Occurence of  " << ch << " is : " << ans << endl;

    // Method 2
    
    cout << "Last Occurence of  " << ch << " is : " << lastOccurenceOfACharacter(s,ch,s.size()-1) << endl;
    return 0;
}