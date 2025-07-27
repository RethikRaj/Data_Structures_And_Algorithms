#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> ans;
        queue<int> q2;
        
        int half = q.size()/2;
        while(half--){
            q2.push(q.front());
            q.pop();
        }
        
        while(!q.empty() && !q2.empty()){
            ans.push_back(q2.front());
            q2.pop();
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};