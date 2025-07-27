#include <iostream>

using namespace std;

// method 1 : basic brute force
void printAllSubstrings(string s) {
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int len=1;len<=n-i;len++){
            cout << s.substr(i,len) << endl;
        }
    }
}

// method 2 : expanding around centre concept
int printAllSubstrings2(string s){
    int count = 0;
    int n = s.length();
    for(int center = 0;center < n;center++){
        // odd length
        int i = center;
        int j = center;
        while(i>=0 && j<n){
            cout << s.substr(i,j-i+1) << endl;
            count++;
            i--;
            j++;
        }
        // even length
        i = center;
        j = center + 1;
        while(i>=0 && j<n){
            cout << s.substr(i,j-i+1) << endl;
            count++;
            i--;
            j++;
        }
    }
    return count;
}

int main(){
    string s = "rethik";
    cout << "Number of substrings is  : " << printAllSubstrings2(s) << endl;
    return 0;
}

