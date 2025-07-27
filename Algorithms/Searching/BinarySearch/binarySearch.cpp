#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
        else if(arr[mid] > target){
            end = mid-1;
        }

        // mid update => VIMP VIMP => DONT FORGET
        mid = start + (end-start)/2;
    }

    return -1;
}




int main() {

  int arr[] = {10,20,30,40,50,60,70,80,90};
  int n = 9;
  int target = 77;
    // Inbuilt binary search
  //bool ans = binary_search(arr,arr+n,target);

  //cout << ans << endl;


  return 0;
}