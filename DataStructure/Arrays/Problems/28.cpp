#include <bits/stdc++.h> 

// Method 1 : reverse , add , reverse
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	// step1 : reverse
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	// step2 : add
	int i = 0;
	int j = 0;
	int carry = 0;
	while(i < a.size() && j < b.size()){
		int sum = a[i] + b[j] + carry;
		int digit = sum%10;
		carry = sum/10;
		ans.push_back(digit);
		i++;
		j++;
	}

	while(i < a.size()){
		int sum = a[i] + carry;
		int digit = sum%10;
		carry = sum/10;
		ans.push_back(digit);
		i++;
	}

	while(j < b.size()){
		int sum = b[j] + carry;
		int digit = sum%10;
		carry = sum/10;
		ans.push_back(digit);
		j++;
	}

	if(carry != 0){
		ans.push_back(carry);
	}

	// step 3 : reverse
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(ans.begin(),ans.end());
	return ans;
}

// Method 2 : add and store and at last reverse only ans arr;
// one more extra also added that is how to handle leading zeroes
class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        string ans;

    	// step1 : add
    	int i = n-1;
    	int j = m-1;
    	int carry = 0;
    	while(i >=0 && j >= 0){
    		int sum = a[i] + b[j] + carry;
    		int digit = sum%10;
    		carry = sum/10;
    		ans.push_back(digit + '0');
    		i--;
    		j--;
    	}
    
    	while(i >= 0){
    		int sum = a[i] + carry;
    		int digit = sum%10;
    		carry = sum/10;
    		ans.push_back(digit + '0');
    		i--;
    	}
    
    	while(j >= 0){
    		int sum = b[j] + carry;
    		int digit = sum%10;
    		carry = sum/10;
    		ans.push_back(digit + '0');
    		j--;
    	}
    
    	if(carry != 0){
    		ans.push_back(carry + '0');
    	}
    
        // remove leading zeroes -> since before reverse ->leading zeroes are present at end
        while(ans[ans.size()-1] == '0'){
            ans.pop_back();
        }
    	// step 2 : reverse
    	reverse(ans.begin(),ans.end());
    	return ans;
    }
};