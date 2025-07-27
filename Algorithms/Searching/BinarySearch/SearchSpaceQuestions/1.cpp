#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Method 1 :
int mySqrt(int x){
    int s = 0;
    int e = x;
    long long int mid = s+(e-s)/2;
    int ans;
    while(s <=e){
        long long int product = mid*mid;
        if(product == x){
            return mid;
        }
        else if(product < x){
            // mid may or may not be ans => store and compute(move right) 
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

double mySqrtWithPrecision(int x,int precision){
    double sqrtAns = mySqrt(x);

    double step = 0.1;
    // outer loop runs precision times
    while(precision--){
        double j = sqrtAns;
        while(j*j <= x){
            sqrtAns = j;
            // update j 
            j+= step;
        }
        // Update step;
        step = step/10;
    }
    return sqrtAns;
}

// Method 2 : 
// This method gives many precision digits handle it with printf or write somrhting like round funcyion at last
double mySqrtWithPrecisionDirect(int x,int precision){
    double start = 0;
    double end = x;
    double mid = start + (end-start)/2;
    double ans = 0;

    double condition = pow(10,-precision);
    //cout << condition << endl;

    while(end - start > condition){
        double predicate = mid*mid;
        if(predicate <= x){
            ans = mid;
            start = mid;
        }else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

// waste : dont see this
double sqrtWithPrecision(int x,int precision){
    int s = 0;
    int e = x;
    long long int mid = s+(e-s)/2;
    int ans = -1;

    while(s <= e){
        long long int product = mid*mid;
        if(product == x){
            return (double)mid;
        }
        else if(product < x){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    // got sqrt without precision

    // double factor = 1;
    // for (int i = 0; i < precision; i++) {
    //     factor = factor / 10;
    //     for (double j = sqrtAns; j * j <= x; j += factor) {
    //         // strore and compute
    //         sqrtAns = j;
    //     }
    // }

    // Using binary search like but double values with eauality operator giving unexpected results.
    
    // for(int i=0;i<precision;i++){
    //     double start = sqrtAns + factor/10;
    //     double end = sqrtAns + 9*(factor/10);
    //     double mid_ = start + (end-start)/2;
    //     double ans_ = -1;
    //     cout << "start : " << start << " " << " end : " << end << " mid : " << mid_ << " factor :" << factor << endl;
    //     while(start-end <= 0){
    //         double prod =  mid_*mid_;
    //         if(prod <= x){
    //             ans_ = mid_;
    //             start = mid_ + factor/10;
    //         }else{
    //             end = mid_ - factor/10;
    //         }
    //         mid_ = round_with_precision(start + (end-start)/2,i+1);
    //         cout << "start : " << start << " " << " end : " << end << " mid : " << mid_ << " factor :" << factor << " ans : "<< ans_ <<endl;
    //         cout << (start-end <= 0.0) << endl;
    //     }
    //     cout << "start : " << start << " " << " end : " << end << " mid : " << mid_ << " factor :" << factor << " ans : "<< ans_ <<endl;
    //     factor = factor/10; 
    //     sqrtAns = ans_;
    // }

    return -1;
}

int main(){
    int x = 63;
    int precision = 8;

    // double ans = sqrtWithPrecision(x,precision);
    //cout << ans << endl;

    // Note : cout only  prints upto 5 precision
    // Therefore if need more precision use printf
    double ans = mySqrtWithPrecision(x,precision);
    printf("Precision with sqrt : %.8f \n",ans);

    ans = mySqrtWithPrecisionDirect(x,precision);
    cout << ans << endl; 
    // required precision
    printf("Precision with sqrt method -2 : %.9f",ans);
}
