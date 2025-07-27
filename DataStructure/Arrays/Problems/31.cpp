#include <iostream>
#include <vector>

using namespace std;

// numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since the missing positive integer will be in the range [1, N+1].

//The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].

// Now, since additional space is not allowed either, the given array itself needs to be used to track it.

//It may be helpful to use the fact that the size of the set we are looking to track is [1, N]
// which happens to be the same size as the size of the array.

// This means we can use the array to track these elements.

// We traverse the array and if A[i] is in [1,N] range, we try to put in the index of same value in the array.

class Solution{
    int firstMissingPositive(vector<int> &A) {
        int n = A.size();
        
        for(int i = 0; i < n;) {
            if(A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            } else {
                i++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }

};