#include<iostream>

using namespace std;

class Solution {
public:
    string convertStringToNumber(string &s){
        string ans = "";
        for(int i=0;i<s.length();i++){
            int curr = s[i]-'a'+1;
            int firstDigit = curr%10;
            curr = curr/10;
            int secondDigit = curr%10;
            curr = curr/10;

            if(secondDigit > 0){
                ans.push_back('0' + secondDigit);
            }
            ans.push_back('0' + firstDigit);
        }
        return ans;
    }

    int transform(string &number,int k){
        // 1st tranform
        int sum = 0;
        for(int i=0;i<number.length();i++){
            sum += (number[i]-'1'+1);
        }

        // remaininig k-1 transform;
        for(int i=0;i<k-1;i++){
            int currSum = 0;
            while(sum > 0){
                int digit = sum%10;
                sum = sum/10;
                currSum += digit;
            }
            sum = currSum;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        string number = convertStringToNumber(s);
        
        int ans = transform(number,k);

        return ans;
    }
};