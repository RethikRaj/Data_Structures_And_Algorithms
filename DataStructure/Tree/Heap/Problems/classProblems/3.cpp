#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() != 1){
            long long ele1 = pq.top();
            pq.pop();
            long long ele2 = pq.top();
            pq.pop();
            
            cost += (ele1 + ele2);
            
            pq.push(ele1 + ele2);
        }
        
        return cost;
    }
};