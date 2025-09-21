#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized: Max-heap of size k
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        for (int i = 0; i < k; i++){ 
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            if (pq.top() > nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    // Simple: Min-heap
    int findKthSmallestUsingMinHeap(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
