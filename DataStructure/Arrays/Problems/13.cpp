#include <iostream>
#include <vector>
using namespace std;

// Method 1 : using visited array
int missingNumber(int nums[],int size) {
    bool temp[size+1];
    
    for(int i=0;i<size;i++){
        temp[nums[i]] = true;
    }

    for(int i=0;i <= size;i++){
        if(temp[i] == false){
            return i;
        }
    }

    return -1;
}

// method 2 : Using sum approach
int missingNumberUsingSumApproach(vector<int>& v){
    int n = v.size();
    int sumOfArray = 0;
    for(int i=0;i<n;i++){
        sumOfArray += v[i];
    }

    int totalSum = n*(n+1)/2;

    int missingNum = totalSum - sumOfArray;

    return missingNum;
}

// Method 4 : Using XOR
int missingNumber(vector<int>& v) {
    int n = v.size();
    int missingNum = 0;
    for(int i=0;i<n;i++){
        missingNum ^= v[i];
    }

    for(int i=0;i<=n;i++){
        missingNum ^= i;
    }

    return missingNum;
}


// Method 3 : Sort && binary Search => Done in binary Search
