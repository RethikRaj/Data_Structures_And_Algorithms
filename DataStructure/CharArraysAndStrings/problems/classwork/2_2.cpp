#include <iostream>
#include <vector>

using namespace std;

// Best Method : TC : O(n)
string removeDuplicatesBest(string s, int k) {
    int n = s.length();
    int i =0;
    int index = 0;
    vector<int> count(n);
    while(index < n){
        s[i] = s[index];

        count[i] = 1;

        if(i > 0 && s[i] == s[i-1]){
            count[i] += count[i-1];
        }

        if(count[i] == k){
            i -= k;
        }

        i++;
        index++;
    }
    return s.substr(0,i);
}

// Method 1 : Check and ADD 

bool isLastKMinusOneCharSameToCurrChar(string s,int k,char ch){
    int i = 0;
    int n = s.length();
    while(i < k-1){
        if(s[n-i-1] != ch){
            return false;
        }
        i++;
    }
    return true;
}

string removeDuplicates(string s,int k){
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        char currChar = s[i];
        if(ans.length() < k-1){
            ans.push_back(currChar);
        }
        else if(isLastKMinusOneCharSameToCurrChar(ans,k,currChar)){// check whether last k-1 characters same to incoming char
            // true then remove last k-1 characters
            cout << "Before earsing : " << ans << endl;
            ans.erase(ans.length()-k+1,k-1);
            cout << "After earsing : " << ans << endl;
        }else{
            ans.push_back(currChar);
        }
        cout << "Ans is : " << ans << endl;
    }
    return ans;
}

// Method 2 : Add and check => Giving 18/21 testcases passed leading to memery exceed error.
bool isLastKCharactersSame(string s,int k){
    int end = s.length()-1;
    while(end > s.length()-k){
        if(s[end] != s[end-1]){
            return false;
        }
        end--;
    }
    return true;
}

string removeDuplicates2(string s, int k) {
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        // First add 
        ans.push_back(s[i]);
        // checking
        if(ans.length() < k){
            continue;
        }else{
            // Checking whether last k characters same
            if(isLastKCharactersSame(ans,k)){
                // true then remove it => erase
                ans.erase(ans.length()-k,k);
            }
        }
        cout << "ans is : " << ans << endl;
    }
    return ans;
}


int main(){
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << "Final ans is : " << removeDuplicates2(s,k);

    return 0;
}