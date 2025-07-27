#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2 =0,sum3=0;
        int maxSize = max(max(N1,N2),N3);
       
        // find sum of each stack
        for(int i=0;i<maxSize;i++){
            if(i<S1.size()){
                sum1 += S1[i];
            }
            if(i<S2.size()){
                sum2 += S2[i];
            }
            if(i<S3.size()){
                sum3 += S3[i];
            }
        }
       
        // solving
        int index1 = 0,index2 = 0,index3 = 0;
        while(index1 < N1 && index2 < N2 && index3 < N3){
            // if sum is equal at any point of time => return tat sum
            if(sum1 == sum2 && sum2 == sum3){
                return sum1;
            }
            
            int minSum = min(min(sum1,sum2),sum3);
            if(sum1 > minSum){
                sum1 -= S1[index1];
                index1++;
            }
           
            if(sum2 > minSum){
                sum2 -= S2[index2];
                index2++;
            }
           
            if(sum3 > minSum){
                sum3 -= S3[index3];
                index3++;
            }
        }
        return 0;
    }
};
