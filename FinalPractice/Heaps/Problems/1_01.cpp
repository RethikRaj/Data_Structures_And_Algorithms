#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // *Best : Optimized 
    int findKthLargest(vector<int>& nums, int k) {
        // We want to find the k-th largest element in the array.
        // Approach: Use a min-heap of size k.
        // - Keep only the k largest elements seen so far in the heap.
        // - The smallest element in the heap (top) will be the k-th largest.

        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 1: Push the first k elements into the heap.
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Step 2: Process the remaining (n - k) elements in the array.
        for (int i = k; i < nums.size(); i++) {
            // If current element is larger than the smallest element in the heap,
            // it means this element should be part of the top k elements.
            if (pq.top() < nums[i]) {
                pq.pop();           // Remove the smallest element from the heap
                pq.push(nums[i]);   // Insert the current larger element
            }
        }

        // Step 3: The heap contains k largest elements.
        // The top (smallest among them) is the k-th largest element in the array.
        return pq.top();
    }

    // Better
    int findKthLargestUsingMaxHeap(vector<int>& nums, int k) {
        priority_queue<int> pq; // Max-heap

        for(int num : nums) {
            pq.push(num);
        }

        // Pop k - 1 times
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        return pq.top();
    }
};
