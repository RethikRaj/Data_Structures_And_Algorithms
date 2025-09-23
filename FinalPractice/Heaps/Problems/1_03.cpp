#include <bits/stdc++.h>
using namespace std;

double getDistance(int x, int y){
    return sqrt((double)x*x + (double)y*y);
}

class Compare{
    public:
        bool operator()(pair<int,int> &p1, pair<int,int> &p2){
            return getDistance(p1.first, p1.second) < getDistance(p2.first, p2.second);
        }
};

class Solution {
public:
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap of size k which will contain the k shortest distance points => Think about k smallest in array logic
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        // Process first k elements
        for(int i = 0; i < k;i++){
            pq.push({points[i][0], points[i][1]});
        }

        // Process next n-k elements
        for(int i = k; i < points.size();i++){
            pair<int,int> topEle = pq.top();
            pair<int,int> currEle = {points[i][0], points[i][1]};

            if(getDistance(topEle.first, topEle.second) > getDistance(currEle.first, currEle.second)){
                pq.pop();
                pq.push(currEle);
            }
        }

        // Create ans
        vector<vector<int>> ans;

        while(!pq.empty()){
            pair<int,int> topEle = pq.top();
            pq.pop();

            ans.push_back({topEle.first, topEle.second});
        }
        return ans;
    }
};