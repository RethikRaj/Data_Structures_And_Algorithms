#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        int arrIndex;
        int eleIndex;

        Node(int val,int arrIndex,int eleIndex){
            this->val = val;
            this->arrIndex = arrIndex;
            this->eleIndex = eleIndex;
        }
};

class CompareNode{
    public:
    bool operator()(Node* &a, Node* &b){
        return a->val > b->val; // Min - heap
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node* , vector<Node*> , CompareNode> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Step 1 : Process first k elements => First element of each list
        for(int i = 0; i < k;i++){
            if(!nums[i].empty()){
                int ele = nums[i][0];
                Node* temp = new Node(ele, i , 0);
                pq.push(temp);
                maxi = max(maxi, ele);
                mini = min(mini, ele);
            }
        }

        int ansStart = mini;
        int ansEnd = maxi;

        // Step 2:
        while(!pq.empty()){
            // Pop
            Node* curr = pq.top();
            pq.pop();

            int currArrIndex = curr->arrIndex;
            int currEleIndex = curr->eleIndex;

            // Process curr Node
            // !The below Step is Important
            mini = curr->val;
            if(maxi-mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }else if(maxi-mini == ansEnd - ansStart && mini < ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }

            // Push next node 
            int nextEleIndex = currEleIndex + 1;
            if(nextEleIndex < nums[currArrIndex].size()){ // valid Index check
                pq.push(new Node(nums[currArrIndex][nextEleIndex], currArrIndex, nextEleIndex));
                maxi = max(maxi, nums[currArrIndex][nextEleIndex]);
            }else{
                break; // Out of bounds in any array, then stop
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};