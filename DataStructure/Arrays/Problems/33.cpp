#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Method- 2
An Efficient Solution can solve this problem in O(N) time using O(N) extra space. Below is detailed solution.

Create two arrays leftMax[] and rightMin[].
Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains maximum element from 0 to i-1 in input array.
Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains minimum element from to N-1 to i+1 in input array.
Traverse input array. For every element A[i], check if A[i] is greater than leftMax[i] and smaller than rightMin[i]. If yes, return 1.
If loops exits and no such element found return 0
Time Complexity- O(N)
Space Complexity- O(N)

Method- 3

A Further Optimization to the above approach is to use only one extra array and traverse input array only twice.
The first traversal is the same as above and fills leftMax[]. Next traversal traverses from the right and keeps track of the minimum. The second traversal also finds the required element.

Time Complexity- O(N)
Space Complexity- O(N)

*/

int perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int> maxEleToLeft(n,INT_MIN);
    
    int maxEle = A[0];
    for(int i=1;i < n-1;i++){
        maxEleToLeft[i] = maxEle;
        maxEle = max(maxEle,A[i]);
    }
    
    int minEle = A[n-1];
    for(int i=n-2;i >= 1;i--){
        if(A[i] > maxEleToLeft[i] && A[i] < minEle){
            return 1;
        }
        minEle = min(minEle,A[i]);
    }
    return 0;
    
}

int perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int> maxEleToLeft(n,INT_MIN);
    vector<int> minEleToRight(n,INT_MAX);
    
    int maxEle = A[0];
    for(int i=1;i < n-1;i++){
        maxEleToLeft[i] = maxEle;
        maxEle = max(maxEle,A[i]);
    }
    
    int minEle = A[n-1];
    for(int i=n-2;i >= 1;i--){
        minEleToRight[i] = minEle;
        minEle = min(minEle,A[i]);
    }
    
    for(int i=1;i<n-1;i++){
        if(A[i] > maxEleToLeft[i] && A[i] < minEleToRight[i]){
            return 1;
        }
    }
    return 0;
}