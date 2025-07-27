#include <iostream>
#include <vector>
using namespace std;


void findFirstOccurrence(vector<int> arr, int n, int target, int &ansIndex) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) {
            //ans found -> may or may not be first occurence
            //store and compute
            ansIndex = mid;
            //kyoki first occurence ki baat hori h
            //toh batao left me jau first occ k liye ya right me 
            //left me jao
            e = mid - 1;
        }
        if(target > arr[mid] ) {
            ///right me jao
            s = mid + 1;
        }
        if(target < arr[mid]) {
            //left me jao 
            e = mid-1;
        }
        //ye main bhul jata hu
        mid = s + (e-s)/2;
    }
}

int main(){
    // Create ans variable and pass by reference .
}