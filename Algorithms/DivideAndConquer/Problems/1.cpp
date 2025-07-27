#include <iostream>
#include <vector>

using namespace std;

void solve2(vector<int> &arr,int low,int high,int &myMax,int &myMin){
    // Base case
    if(low == high){
        myMax= arr[low];
        myMin = arr[low];
        return;
    }

    // 1 case me solve remaining recursion
    // Divide
    int mid = low + (high-low)/2;
    // solve subproblems
    solve(arr,low,mid,myMax,myMin);
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    solve(arr,mid+1,high,max1,min1);

    if(myMax < max1){
        myMax = max1;
    }
    if(myMin > min1){
        myMin = min1;
    }

}

void solve(vector<int> &arr,int low,int high,int &myMax,int &myMin){
    // Base case
    if(low == high){
        myMax= max(myMax,arr[low]);
        myMin = min(myMin,arr[low]);
        return;
    }

    // 1 case me solve remaining recursion
    // Divide
    int mid = low + (high-low)/2;
    // solve subproblems
    solve(arr,low,mid,myMax,myMin);
    solve(arr,mid+1,high,myMax,myMin);
}

pair<int,int> findMaxMin(vector<int> &arr){
    int myMax = INT_MIN;
    int myMin = INT_MAX;

    solve(arr,0,arr.size()-1,myMax,myMin);

    return make_pair(myMax,myMin);
}

int main(){
    vector<int> arr = {0,-1,0};
    
    pair<int,int> maxMin = findMaxMin(arr);
    cout << "Maximum number is : " << maxMin.first << endl;
    cout << "Minimum number is : " << maxMin.second << endl;
    
    return 0;
}
