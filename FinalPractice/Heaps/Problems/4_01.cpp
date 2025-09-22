#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Prefer this 
class MedianFinderOne {
public:
    priority_queue<int> maxHeap; // left side (smaller half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side (larger half)
    double median;

    MedianFinderOne() {
        median = 0.0;
    }
    
    void addNum(int num) {
        // Step 1: Insert into appropriate heap
        if (num > median) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        // Step 2: Balance sizes (difference ≤ 1)
        if (maxHeap.size() > minHeap.size() + 1) {
            int temp = maxHeap.top();
            minHeap.push(temp);
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            int temp = minHeap.top();
            maxHeap.push(temp);
            minHeap.pop();
        }

        // Step 3: Update median
        if (maxHeap.size() == minHeap.size()) {
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            median = maxHeap.top();
        } else {
            median = minHeap.top();
        }
    }
    
    double findMedian() {
        return median;
    }
};




class MedianFinderTwo {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;

    MedianFinderTwo() {
        
    }
    
    void addNum(int num) {
        // Step 1 : Add to maxHeap
        maxHeap.push(num);

        // Step 2 : Check Elements in max Heap <= elements in minHeap which is equivalent to checking max(maxheap) <= min(minHeap)
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
            // Pop from maxHeap and push to minHeap
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }

        // Step 3 : Balance the sizes => If diff is greater than 1 pop from bigger and push it to smaller
        if(maxHeap.size() > minHeap.size() + 1){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }else if(minHeap.size() > maxHeap.size() + 1){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        else if(maxHeap.size() < minHeap.size()){
            return minHeap.top();
        }else{
            return (maxHeap.top() + minHeap.top())/(double)2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */