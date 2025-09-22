#include <bits/stdc++.h>
using namespace std;

// Node class to store value and its origin
class Node {
public:
    int val;      // value of element
    int arrIdx;   // which array it comes from
    int eleIdx;   // index in that array

    Node(int v, int aIdx, int eIdx) {
        val = v;
        arrIdx = aIdx;
        eleIdx = eIdx;
    }
};

class CompareNode {
public:
    bool operator()(Node* &a,Node* &b) {
        return a->val > b->val;  // min-heap
    }
};

class Solution {
  public:
    /*
    How it works:
    1. Push first element of each array into the heap.
    2. Pop the smallest element from the heap → push it into result.
    3. Push the next element from the same array into the heap.
    4. Repeat until heap is empty.
    */
    vector<int> mergeKArraysOptimised(vector<vector<int>>& arr, int K) {
        int k = arr.size();
        priority_queue<Node*, vector<Node*>, CompareNode> pq; // using functor
        vector<int> result;

        // *1. Process first k elements => Push the first element of each array into heap
        for (int i = 0; i < k; i++) {
            if (!arr[i].empty()){
                Node* temp = new Node(arr[i][0], i, 0);
                pq.push(temp);
            }                
        }

        // Extract min and push next element from same array
        while (!pq.empty()) {
            // *Step 2 : Pop the top element
            Node* curr = pq.top(); 
            pq.pop();
            result.push_back(curr->val);

            // *Step 3 : Check whether next element is present in the same array and push
            int currIndex = curr->eleIdx;
            int currArrayIndex = curr->arrIdx;

            int nextIndex = currIndex + 1;

            if (nextIndex < arr[currArrayIndex].size()) {
                Node* temp = new Node(arr[currArrayIndex][nextIndex], currArrayIndex, nextIndex);
                pq.push(temp);
            }
            
        }

        return result;
    }


    vector<int> mergeKArraysBruteForce(vector<vector<int>> arr, int K) {
        int k = arr.size();                // number of arrays
        vector<int> index(k, 0);           // pointers for each array
        vector<int> result;
    
        // Keep merging until all arrays are fully traversed
        while (true) {
            int minVal = INT_MAX;
            int minIndex = -1;
    
            // Find the smallest among current elements of all arrays
            for (int i = 0; i < k; i++) {
                if (index[i] < arr[i].size()) {  // only consider valid pointers
                    if (arr[i][index[i]] < minVal) {
                        minVal = arr[i][index[i]];
                        minIndex = i;
                    }
                }
            }
    
            // If no valid index found, we are done
            if (minIndex == -1) break;
    
            // Push the min element to result
            result.push_back(minVal);
    
            // Move pointer in the array from which min element was taken
            index[minIndex]++;
        }
    
        return result;
        
    }
};