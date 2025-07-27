#include <iostream>
#include <vector>

using namespace std;

int NthRoot(int n, int m){
    int s = 0;
    int e = m;
    long long int mid = s+(e-s)/2;
    int ans = -1;
    
    while(s<=e){
        long long int predicate = 1;
        for(int i=0;i<n;i++){
            predicate = predicate*mid;
            if(predicate > m){
                break;
            }
        }
        cout << predicate << endl;
        if(predicate == m){
            return mid;
        }else if(predicate < m){
            //ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}  

int main(){
    int n = 6;
    int m = 4096;
    cout << NthRoot(n,m) << endl;
    return 0;
}