#include<iostream>
#include<vector>
using namespace std;

bool isArraySorted2(vector<int> arr,int index){
    if(index == arr.size()-1){
        return true;
    }
    // 1case i solve
    bool myCase = arr[index] <= arr[index+1];
    // Remaininig
    bool recKaAns = isArraySorted2(arr,index+1);

    return myCase && recKaAns;
}

bool isArraySorted(vector<int> arr,int index){
    if(index == arr.size()-1){
        return true;
    }
    // 1 case i will solve
    if(arr[index] > arr[index+1]){
        return false;
    }
    // Remaining recursion
    return isArraySorted(arr,index+1);
}

int main(){
    vector<int> arr = {10,20,30,30,50,60,10};
    bool isSorted = isArraySorted2(arr,0);
    if(isSorted){
        cout << "Array is Sorted." << endl;
    }else{
        cout << "Array is unsorted." << endl;
    }
    return 0;
}