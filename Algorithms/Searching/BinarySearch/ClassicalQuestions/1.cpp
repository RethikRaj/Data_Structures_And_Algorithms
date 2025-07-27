#include <iostream>
#include <vector>

using namespace std;

int findFirstOccurence(vector<int>& arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    int ansIndex = -1;

    while(start <= end){
        if(arr[mid] == target){
            // target's first occurence may be present in left so store and move left
            ansIndex = mid; // store
            end = mid-1; // move left
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

    return ansIndex;
}

int findLastOccurence(vector<int>& arr,int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    int ansIndex = -1;

    while(start <= end){
        if(arr[mid] == target){
            // target's last occurence may be present in right => so store and move right
            ansIndex = mid; // store
            start = mid+1; // move right
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

    return ansIndex;
}


int findTotalOccurences(vector<int>& arr,int target){
    int firstOccurence = findFirstOccurence(arr,target);
    if(firstOccurence == -1){
        // target not found;
        return 0;
    }
    int lastOccurence = findLastOccurence(arr,target);
    int totalOccurences = lastOccurence - firstOccurence + 1;
    return totalOccurences;
}

int main(){
    vector<int> v = {10,20,30,30,30,30,30,40,50,60,70};
    int target = 30;

    cout << "The first occurence of " << target << " is : " << findFirstOccurence(v,target) << endl;
    cout << "The last occurence of " << target << " is : " << findLastOccurence(v,target) << endl;
    cout << "The total occurences of " << target << " is : " << findTotalOccurences(v,target) << endl;

    return 0;
}
