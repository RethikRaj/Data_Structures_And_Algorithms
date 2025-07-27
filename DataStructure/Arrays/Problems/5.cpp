#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// method 1 : XOR
int findUnique(int arr[],int size){
    int answer = 0;
    for(int i=0;i<size;i++){
        answer = answer ^ arr[i];
    }
    return answer;
}

// Method 2 : Hashing
int findUnique2(int arr[],int size){
    unordered_map<int,int> mapping;

    for(int i=0;i<size;i++){
        mapping[arr[i]]++;
    }

    unordered_map<int,int>::iterator it = mapping.begin();
    while(it != mapping.end()){
        if((*it).second == 1){
            return (*it).first;
        }
        it++;
    }

    return -1;
}

// sum method : 2*uniqueSum - arraySum
int findUnique3(int arr[],int size){
    unordered_set<int> s;

    for(int i=0;i<size;i++){
        s.insert(arr[i]);
    }

    int setSum = 0;
    unordered_set<int>::iterator it = s.begin();
    while(it != s.end()){
        setSum += (*it);
        it++;
    }

    int arraySum = 0;
    for(int i=0;i<size;i++){
        arraySum += arr[i];
    }

    return 2*setSum - arraySum;
}

// Sorting method 
int findUnique4(int arr[],int size){
    sort(arr,arr+size);
    int ans = -1;

    for(int i=0;i<size;){
        if(i+1<size && arr[i] == arr[i+1]){
            i+=2;
        }else{
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int main(){
    int arr[] = {10,5,1,12,10,12,1};
    int n = 7;
    cout << "Unique Element is : " << findUnique(arr,n) << endl;
    cout << "Unique Element is : " << findUnique2(arr,n) << endl;
    cout << "Unique Element is : " << findUnique3(arr,n) << endl;
    cout << "Unique Element is : " << findUnique4(arr,n) << endl;
    return 0;
}