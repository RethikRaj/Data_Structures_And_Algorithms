#include<iostream>
#include<math.h>
using namespace std;

// sqrt approach => TC : O(sqrt(n))
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

// Naive Approach => TC : O(n)
 bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<n/2;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}