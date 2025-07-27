#include <iostream>
using namespace std;

void printPairs(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;

    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;

    for(int i=0;i<size;i++){
        for(int j=0;j<=i;j++){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;

    for(int i=0;i<size;i++){
        for(int j=size-1;j>=0;j--){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;

    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
        }
    }

    cout << endl << endl;


}


int main(){
    int arr[] = {10,20,30,40};
    int n = 4;
    printPairs(arr,n);
}