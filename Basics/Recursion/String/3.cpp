#include<iostream>
using namespace std;

// Method 2 : Externally no need to pad Zeroes

void addStringsUtility(string& num1,int p1,string& num2,int p2,string& ans,int carry){
    if(p1 < 0 && p2 < 0){ // base case
        // carry may be or may not be zero
        if(carry != 0){
            ans = (char)(carry+'0') + ans;
        }
        return;
    }

    // 1 case me solve
    int digit1 = p1 >=0 ? num1[p1]-'0' : 0;
    int digit2 = p2 >=0 ? num2[p2]-'0' : 0;
    int myAns = digit1 + digit2 + carry;
    int toAdd = myAns % 10;
    carry = myAns/10;

    // Remaining recursion
    addStringsUtility(num1,p1-1,num2,p2-1,ans,carry);

    // Backtracking
    char toAddChar = toAdd + '0';
    ans.push_back(toAddChar);
}

string addStrings(string num1, string num2) {
    string ans = "";
    addStringsUtility(num1,num1.length()-1,num2,num2.length()-1,ans,0);
    return ans;
}



// Method 1 : Externally need to pad zeroes

void padZeroes(string& small,int noOfZeroes){
    for(int i=0;i<noOfZeroes;i++){
        small.insert(0,"0");
    }
}

void addStringsUtility(string& num1,string& num2,string& ans,int index,int& carry){
    if(index < 0){
        return;
    }
    // 1 case me solve
    int digit1 = num1[index]-'0';
    int digit2 = num2[index]-'0';
    int myAns = digit1 + digit2 + carry;
    int toAdd = myAns % 10;
    carry = myAns/10;

    // Remaining recursion
    addStringsUtility(num1,num2,ans,index-1,carry);

    // Backtracking
    char toAddChar = toAdd + '0';
    ans.push_back(toAddChar);
}

string addStrings(string num1, string num2) {
    // Pad abs(num1-num2) no of zeroes to the min length string
    int n1 = num1.length();
    int n2 = num2.length();
    if(n1 < n2){
        // Pad to num1
        padZeroes(num1,abs(n1-n2));
    }
    else if(n1 > n2){
        // Pad to num2
        padZeroes(num2,abs(n1-n2));
    }


    string ans = "";
    int carry = 0;
    addStringsUtility(num1,num2,ans,num1.length()-1,carry);
    if(carry != 0){
        char toInsert = carry + '0';
        ans = toInsert + ans;
    }
    return ans;
}