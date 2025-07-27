#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


void selectionSort(vector<int>& v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        int mineleIndex = i;
        for(int j=i+1;j<n;j++){
            if(v[mineleIndex] > v[j]){
                mineleIndex = j;
            }
        }
        // swap v[i] and v[mineleIndex]
        swap(v[i],v[mineleIndex]);
    }
}