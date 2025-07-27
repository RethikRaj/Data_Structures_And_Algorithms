#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

class Info{
    public:
        int x;
        int y;
        double distance;

        Info(int x,int y){
            this->x = x;
            this->y = y;
            this->distance = sqrt(pow(x,2) + pow(y,2));
        }
};

class compare{
    public:
        bool operator()(Info* a,Info* b){
            return a->distance < b->distance;
        }
};

class Solution {
public:    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap -> Because think about the logic : k smallest in array
        priority_queue<Info*,vector<Info*>,compare> pq;

        // process first k elements->Initial State
        for(int i=0;i<k;i++){
            Info* temp = new Info(points[i][0],points[i][1]);
            pq.push(temp);
        }

        // process remaining elements
        for(int i=k;i<points.size();i++){
            Info* temp = new Info(points[i][0],points[i][1]);
            Info* front = pq.top();
            if(front->distance > temp->distance){
                pq.pop();
                pq.push(temp);
            }
        }

        // create ans
        vector<vector<int>> ans;
        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();

            vector<int> pair(2);
            pair[0] = front->x;
            pair[1] = front->y;
            ans.push_back(pair);
        }
        return ans;
    }
};
