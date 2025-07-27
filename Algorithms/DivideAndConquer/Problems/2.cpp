#include <iostream>
#include <vector>

using namespace std;

// using divide n conquer



// Kadanes using recursion
void solve(vector<int> &arr,int index,int &sum,int &maxSum){
    // Base case
    if(index >= arr.size()){
        return;
    }
    // 1 case me solve remaining recursion will handle
    sum += arr[index];
    maxSum = max(maxSum,sum);
    if(sum < 0){
        sum = 0;
    }
    solve(arr,index+1,sum,maxSum);
}

void maximumSubArray(vector<int> &arr){
    int sum = 0;
    int maxSum = INT_MIN;
    solve(arr,0,sum,maxSum);
}

int main(){

}