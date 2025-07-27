#include<iostream>
#include <vector>

using namespace std;

vector<int> findTwosComplement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n+1,0);

    // Step 1 : Flip and store in ans
    for(int i=n-1;i>=0;i--){
        ans[i+1] = (arr[i] == 0) ? 1 : 0;
    }

    // Step 2 : add one
    int carry = 1;
    for(int i=ans.size()-1;i>=1;i--){
        int sum = ans[i] + carry;
        ans[i] = sum%2;
        carry = sum/2;
        // optimization
        if(carry == 0){
            break;
        }
    }
    if(carry == 1){
        ans[0] = 1;
    }
    return ans;
}


vector<int> findTwosComplement2(vector<int> &arr){
    vector<int> ans(arr.size());
    // 
    bool firstOneFromLastFound = false;
    for(int i=arr.size()-1;i>=0;i--){
        if(firstOneFromLastFound == true){
            // flip
            ans[i] = (arr[i] == 0) ? 1:0;
        }else{
            ans[i] = arr[i];
            firstOneFromLastFound = (arr[i] == 1);
        }
    }
    return ans;
}

int main(){
    vector<int> input = {0,0,0,0,0,0};
    //vector<int> output = findTwosComplement(input);
    vector<int> output = findTwosComplement2(input);

    // print ans -> Note ignore first bit
    for(int i=0;i<output.size();i++){
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}


