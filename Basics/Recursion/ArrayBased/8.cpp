#include <iostream>
#include <vector>


using namespace std;

void solveUtility(vector<int> &A,int index,int x,bool &ans){
    if(index >= A.size()){
        ans = true;
        return;
    }
    
    // option 1 
    A[index] += x;
    if(index == 0 || A[index] == A[index-1]){
        solveUtility(A,index+1,x,ans);
    }
    // backtrack
    A[index] -= x;
    
    
    // opttion 2
    A[index] -= x;
    if(index == 0 || A[index] == A[index-1]){
        solveUtility(A,index+1,x,ans);
    }
    A[index] += x;
    
    // option 3
    if(index == 0 || A[index] == A[index-1]){
        solveUtility(A,index+1,x,ans);
    }
}

int solve(vector<int> &A, int B) {
    bool ans = false;
    solveUtility(A,0,B,ans);
    return ans;
}