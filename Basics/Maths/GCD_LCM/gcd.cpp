#include<iostream>

using namespace std;


// Method 2
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Method 1

int gcd(int a, int b) {
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    
    while(a>0 && b>0){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    // Comes here if either a == 0 or b == 0 => if (a==0) return b else return a
    return a == 0 ? b : a;
}