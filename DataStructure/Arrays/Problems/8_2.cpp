#include <iostream>
using namespace std;


// colors : 0 ,1 ,2, ... ,k-1

void sortKColors(int arr[],int size,int k){
    // Step 1 : counting
    int colorCount[k] = {0}; // before we used variables now since k=> use array otherwise we need k variables and also k is unknown

    for(int i=0;i<size;i++){
        // // arr[i] can have value from 0 to k-1 => need k conditions to check => use loop
        // for(int j=0;j<=k-1;j++){
        //     if(arr[i] == j){
        //         colorCount[j]++;
        //         break;
        //     }
        // }

        colorCount[arr[i]]++;
    }

    int index = 0;
    for(int color=0;color<k;color++){
        while(colorCount[color]--){
            arr[index] = color;
            index++;
        }
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4, 0, 3, 2, 1, 4, 1, 0, 2, 3, 1, 4, 0, 3, 2};
    int n = 15;
    int k = 5; // number of colors
    sortKColors(arr,n,k);
    printArray(arr,n);
    return 0;
}