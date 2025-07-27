#include <iostream>
using namespace std;

void printTriplets(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int z=0;z<size;z++){
                cout << "[" << arr[i] << "," << arr[j] << "," << arr[z] << "]" << endl;
            }
        }
    }
}

void threeSum(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int z=0;z<size;z++){
                if(arr[i] + arr[j]+arr[z] == target){
                    cout << "Indexes are : " << i << "," << j << "," << z << "]" << endl;
                }
            }
        }
    }
}

int main(){
    int arr[] = {10,20,30,40};
    int n = 4;

    printTriplets(arr,n);
    
}