#include<iostream>
using namespace std;

void reverseAString(string& s,int start,int end){
    if(start > end){ // base case
        return;
    }
    // 1 case me solve
    swap(s[start],s[end]);
    // Remaining recursion
    reverseAString(s,start+1,end-1);
}

int main(){
    string s = "Rethik";
    reverseAString(s,0,s.size()-1);
    cout << s << endl;
    return 0;
}