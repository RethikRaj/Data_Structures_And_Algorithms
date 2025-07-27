#include<iostream>
#include<vector>
using namespace std;

// Method 2 : (Different implementation)
// util prints one set that is having same start point
void printAllSubarrays2_util(int arr[],int size,int start,int end){
    if(end >= size){
        return;
    }
    // 1 case me solve
    for(int i= start;i<=end;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // remaining recursion
    printAllSubarrays2_util(arr,size,start,end+1);
}

void printAllSubarrays2(int arr[],int size){
    for(int start=0;start<size;start++){
        int end = start;
        printAllSubarrays2_util(arr,size,start,end);
    }
}

// Method 2
void printAllSubarrays2(int arr[],int size,int start,int end){
    if(start >= size){
        return;
    }
    if(end >= size){
        printAllSubarrays2(arr,size,start+1,start+1);
        return;
    }
    // 1 case me solve
    for(int i= start;i<=end;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // Remaining recursion
    printAllSubarrays2(arr,size,start,end+1);
}

// Method 1;
void printAllSubarrays(int arr[],int size,int start){
    if(start >= size){
        return;
    }
    // 1 case me solve
    for(int end = start;end<size;end++){
        // Print from start to end;
        for(int j = start;j<=end;j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Remaining recursion
    printAllSubarrays(arr,size,start+1);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = 7;
    //printAllSubarrays(arr,size,0);
    //printAllSubarrays2(arr,size,0,0);
    printAllSubarrays2(arr,size);
    return 0;
}