#include<iostream>
using namespace std;

void maxInArray(int arr[],int size,int index,int& maxAns){
    if(index == size){ // base case
        return;
    }
    // 1 case i do
    maxAns = max(arr[index],maxAns);
    // Remaining recusion takes care
    minInArray(arr,size,index+1,maxAns);
}

int maxInArray(int arr[],int size,int index){
    if(index == size){ // base case
        return INT_MIN;
    }
    return max(arr[index],maxInArray(arr,size,index+1));
}

void minInArray(int arr[],int size,int index,int& minAns){
    if(index == size){ // base case
        return;
    }
    // 1 case i do
    minAns = min(arr[index],minAns);
    // Remaining recusion takes care
    minInArray(arr,size,index+1,minAns);
}


int main(){

    int arr[] = {10,20,30,40,50,60,70};
    int size = 7;
    // int maxAns = INT_MIN;
    // maxInArray(arr,size,0,maxAns);
    // cout << "Maximum is : " << maxAns << endl;

    // Method 2 :
    int maxAns = maxInArray(arr,size,0);
    cout << "Maximum is : " << maxAns << endl;




    return 0;
}