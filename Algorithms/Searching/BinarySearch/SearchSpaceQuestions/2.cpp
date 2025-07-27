#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// method1 : Binary Search(non-precision) + linear to get precision

int divide(int dividend, int divisor) {
    long long int myDividend = abs(dividend);
    long long int myDivisor = abs(divisor);

    // Search Space => 0 to dividend
    long long int s = 0;
    long long int e = myDividend;
    long long int mid = s+((e-s)>>1);
    long long int ans = 0;

    while(s <= e){
        long long int predicate = mid * myDivisor;
        if(predicate <= myDividend){
            // store and compute.
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+((e-s)>>1);
    }

    
    if(dividend < 0){
        ans = -1*ans;
    }
    
    if(divisor < 0){
        ans = -1*ans;
    }
    
    // Answer exceeds integer range.
    if(ans > INT_MAX){
        return INT_MAX;
    }
    return ans;
}

double divideWithPrecision(int dividend,int divisor,int precision){
    long long int myDividend = abs(dividend);
    long long int myDivisor = abs(divisor);
    
    double myAns = (double) (divide(dividend,divisor));
    if(myAns < 0){
        myAns *= -1;
    }
    double step = 0.1;

    for(int i=0;i<precision;i++){
        
        double j = myAns;
        while(j*myDivisor <= myDividend){
            // Strore and compute
            myAns = j;
            j += step;
        }
        step = step/10;
    }

    // handling answer +ve or -ve
    if(divisor < 0){
        myAns *= -1;
    }
    if(dividend <0){
        myAns *= -1;
    }
    return myAns;
}

// Merhod 2 : BinarySearch(non-precision)

double divideWithPrecisionDirect(int dividend,int divisor,int precision){
    long long int myDivisor = abs(divisor);
    long long int myDividend = abs(dividend);

    double s = 0;
    double e = myDividend;
    double mid = s + ((e-s)/2);
    double ans = 0;

    double condition = pow(10,-precision);

    while(e - s > condition){
        double predicate = mid*myDivisor;
        if(predicate <= myDividend){
            ans = mid;
            s = mid;
        }else{
            e = mid;
        }
        mid = s + ((e-s)/2);
    }

    if(dividend <0){
        ans *= -1;
    }
    if(divisor < 0){
        ans *= -1;
    }
    return ans;
}


int main(){
    int dividend = -10;
    int divisor = -3;
    int precision = 8;
    cout << divideWithPrecision(dividend,divisor,precision) << endl;

    double ans = divideWithPrecisionDirect(dividend,divisor,precision);
    printf("quotient with precision %.8f" , ans);
    return 0;
}