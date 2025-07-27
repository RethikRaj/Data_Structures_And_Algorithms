#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findMissingNumber(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    int ans = -1;;
    while(start <= end){
        if(arr[mid] != mid){
            // mid might be finalAns or may not be finalAns =>store and compute =>store and move left
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid] == mid){
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    if(ans == -1){ // last number in range missing 
        return arr.size();
    }

    return ans;
}

int main(){
    vector<int> v = {0,1,2,3,4,5,6,7};
    int n = 8; // n represents size

    cout << "The missing element is : " << findMissingNumber(v) << endl;

    return 0;
}