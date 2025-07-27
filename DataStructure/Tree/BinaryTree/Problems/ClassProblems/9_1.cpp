#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<Node*,int>> q;
        // initial state
        q.push(make_pair(root,0));
        unordered_map<int,Node*> mp; // HorizontalDistance->node*
        int minHD = INT_MAX;
        int maxHD = INT_MIN;
        
        while(!q.empty()){
            pair<Node*,int> frontPair = q.front();
            q.pop();
            Node* frontNode = frontPair.first;
            int horizontalDistance = frontPair.second;
            minHD = min(minHD,horizontalDistance);
            maxHD = max(maxHD,horizontalDistance);
            
            // since i need lastOccurence of each HD => even if same HD occurs , just update
            mp[horizontalDistance] = frontNode;
            
            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left,horizontalDistance-1));
            }
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right,horizontalDistance+1));
            }
        }
        
        // make ans;
        for(int i=minHD;i<=maxHD;i++){
            Node* temp = mp[i];
            ans.push_back(temp->data);
        }
        
        return ans;
    }
};