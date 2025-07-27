#include<iostream>
#include<vector>
using namespace std;

void printEven(int arr[],int size,int index){
    if(index == size){
        return;
    }
    // One case 
    if(arr[index]&1 == 0){
        cout << arr[index] << " ";
    }
    // remaining
    printEven(arr,size,index+1);
}

void printOdd(int arr[],int size,int index){
    if(index == size){
        return;
    }
    // One case 
    if(arr[index]&1 == 1){
        cout << arr[index] << " ";
    }
    // remaining
    printOdd(arr,size,index+1);
}

void storeOdd(int arr[],int size,int index,vector<int> &ans){
    if(index == size){
        return;
    }
    // One case 
    if(arr[index]&1 == 1){
        ans.push_back(arr[index]);
    }
    // remaining
    storeOdd(arr,size,index+1,ans);
}

int main(){
    int arr[] = {10,39,40,23,45,67,888,99};
    int size = 8;
    vector<int> ans;
    storeOdd(arr,size,0,ans);
    // Print ans
    vector<int>::iterator it = ans.begin();
    while(it != ans.end()){
        cout << *it << " ";
        it++;
    }
    return 0;
}