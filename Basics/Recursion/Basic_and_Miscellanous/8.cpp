#include<iostream>
using namespace std;

class Solution {
public:
    // Method 2 : a^n = a^(n/2)*a^(n/2) if n is even
    double method2(double &x,long long int n){
        if(n == 0){
            return 1;
        }
        else{
            double xPowerNby2 = method2(x,n/2);
            if((n&1) == 0){
                // if n is even
                return xPowerNby2*xPowerNby2;
            }else{
                // if n is odd
                return x*xPowerNby2*xPowerNby2;
            }
        }
    }

    // Method 1 : a^n = a*a^(n-1)
    // Stack overflow
    double method1(double &x,long long int n){
        if(n==0){
            return 1;
        }else{
            return x*method1(x,n-1);
        }
    }

    double myPow(double x, int n) {
        bool isNLessThanZero = false;
        long long int n1 = n;
        if(n < 0){
            isNLessThanZero = true;
            n1 = -1*(long long int)n;
        }
        
        //double ans = method1(x,n1);
        double ans = method2(x,n1);
        if(isNLessThanZero == false){
            return ans;
        }else{
            return 1/ans;
        }
    }
};