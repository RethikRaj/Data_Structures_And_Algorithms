#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// n -> Number of columns , k->no of rows


// Method 2 :

// Info class is required so that i can check whether next element is present in the row in which i got a min element
class Info{
    public:
        int data;
        int rIndex;
        int cIndex;
        
        Info(int x, int y, int z) {
            this->data = x;
            this->rIndex = y;
            this->cIndex = z;
        }
};

class compare{
 public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data; // min heap
        //return a->data < b->data; max heap
    }
};

class Solution{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        int totalRows = arr.size();
        int totalColumns = arr[0].size();

        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;

        // Initial state -> Push first element in each row into pq;
        for(int row=0; row<totalRows; row++) {
            int element = arr[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
        }
        
        // Processing
        while(!pq.empty()) {
            Info* front = pq.top();
            pq.pop();
            
            //include in answer
            int frontdata = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;
            ans.push_back(frontdata);
            
            //check if more elements are present in front_row or not 
            if(front_cIndex+1 < totalColumns) {
                int element = arr[front_rIndex][front_cIndex+1];
                Info* temp = new Info(element, front_rIndex,front_cIndex+1 );
                pq.push(temp);
            }
        }
        return ans;
    }
};


// Method 1: Merge last two and push it 

// D and C Merge : TC:O(n*k(logK))
class Solution{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeTwoSortedArrays(vector<int> arr1,vector<int> arr2){
        vector<int> ans;
        int i=0,j=0;
        
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
    
    // Function to merge k sorted arrays using divide and conquer approach.
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int start, int end) {
        // Base case: if there's only one array, return it.
        if (start == end) {
            return arr[start];
        }
        
        // Divide the arrays into two halves.
        int mid = start + (end - start) / 2;
        
        // Recursively merge the left half and right half.
        vector<int> leftMerged = mergeKSortedArrays(arr, start, mid);
        vector<int> rightMerged = mergeKSortedArrays(arr, mid + 1, end);
        
        // Merge the two halves.
        return mergeTwoSortedArrays(leftMerged, rightMerged);
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        return mergeKSortedArrays(arr,0,K-1);
    }
};



// Linear Merge : TC: O(n*K2)
class Solution{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeTwoSortedArrays(vector<int> arr1,vector<int> arr2){
        vector<int> ans;
        int i=0,j=0;
        
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        for(int i=0;i<K-1;i++){
            vector<int> last = arr[arr.size()-1];
            arr.pop_back();
            vector<int> secondLast = arr[arr.size()-1];
            arr.pop_back();
            
            vector<int> mergedArray = mergeTwoSortedArrays(last,secondLast);
            arr.push_back(mergedArray);
        }
        
        return arr[0];
    }
};