#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void multiply(vector<int> &ans,int x){
        //step 1 : reverse
        reverse(ans.begin(),ans.end());
        // step2: multiply
        int carry = 0;
        for(int i=0;i<ans.size();i++){
            int product = ans[i]*x + carry;
            ans[i] = product%10;
            carry = product/10;
        }
        // imp dont use if use while(carry >0)
        while(carry > 0){
            ans.push_back(carry%10);
            carry = carry/10;
        }
        // step 3: reverse
        reverse(ans.begin(),ans.end());
    }
    
    
    
    vector<int> factorial(int N){
        vector<int> fact = {1};
        for(int i=1;i<=N;i++){
            multiply(fact,i);   
        }
        return fact;
    }
};