#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class compare{
    public:
        // didnt work

        // bool operator()(string a,string b){
        //     int i = 0;
        //     int j = 0;
        //     while(i < a.length() && j < b.length()){
        //         int digit_a = a[i]-'0'+0;
        //         int digit_b = b[i]-'0'+0;
        //         if(digit_a > digit_b){
        //             // a is larger
        //             return false;
        //         }else if(digit_a < digit_b){
        //             // b is larger
        //             return true;
        //         }else{
        //             i++;
        //             j++;
        //         }
        //     }
        //     while(i < a.length()){
        //         int last_digit_b = b[b.length()-1]-'0'+0;
        //         int curr_digit_a = a[i]-'0'+0;
        //         if(curr_digit_a > last_digit_b){
        //             // a is larger
        //             return false;
        //         }else if(curr_digit_a < last_digit_b){
        //             // b is larger
        //             return true;
        //         }else{
        //             i++;
        //         }
        //     }
        //     while(j < b.length()){
        //         int last_digit_a = a[a.length()-1]-'0'+0;
        //         int curr_digit_b = b[j]-'0'+0;
        //         if(last_digit_a > curr_digit_b){
        //             // a is larger
        //             return false;
        //         }else if(last_digit_a < curr_digit_b){
        //             // b is larger
        //             return true;
        //         }else{
        //             i++;
        //         }
        //     }
        //     return true;
        // }

        bool operator()(string a,string b){
            string s1 = a+b;
            string s2 = b+a;

            int i=0;
            int j=0;
            while(i < s1.length() && j < s2.length()){
                int curr_digit_s1 = s1[i]-'0'+0;
                int curr_digit_s2 = s2[j]-'0'+0;
                if(curr_digit_s1 > curr_digit_s2){
                    return false;
                }
                else if(curr_digit_s1 < curr_digit_s2){
                    return true;
                }
                else{
                    i++;
                    j++;
                }
            }
            // all numbers equal
            return true;
        }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string,vector<string>,compare> pq;
        for(int i=0;i<nums.size();i++){
            string curr = to_string(nums[i]);
            pq.push(curr);
        }

        string ans = "";
        if(pq.top().compare("0") == 0){
            return "0";
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};