#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// max heap checking

// Method 1 : Checking completeness along with heap property simultaneously
class Solution {
  public:
    bool isHeap(struct Node* tree) {
        queue<Node*> q;
        q.push(tree);

        bool isFirstNullArrived = false;

        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            if(front == NULL){
                if(isFirstNullArrived){
                    continue;
                }else{
                    isFirstNullArrived = true;
                }
            }
            else if(front != NULL){
                if(isFirstNullArrived){
                    // completeeness checking
                    return false;
                }else{
                    // heap condition
                    if(front->left != NULL && front->left->data > front->data){
                        return false;
                    }
                    if(front->right != NULL && front->right->data > front->data){
                        return false;
                    }
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
};

// method 2 : Checking completeness separately and then checking heap property separately

class Solution {
  public:
    int nodeCount(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1+nodeCount(root->left)+nodeCount(root->right);
    }

    bool checkCompleteness(Node* root,int index,int &totalNodes){
        if(!root){
            return true;
        }
        // 
        if(index > totalNodes){
            return false;
        }
        return checkCompleteness(root->left,2*index,totalNodes) && checkCompleteness(root->right,2*index+1,totalNodes);
    }
    
    bool checkMaxHeapProperty(Node* root){
        if(!root){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        bool leftRecAns = checkMaxHeapProperty(root->left);
        bool rightRecAns = checkMaxHeapProperty(root->right);
        
        bool currAns = true;
        if(root->left != NULL && root->data < root->left->data){
            currAns = false;
        }
        if(root->right != NULL && root->data < root->right->data){
            currAns = false;
        }
        
        return currAns && leftRecAns && rightRecAns;
    }
  
    bool isHeap(struct Node* tree) {
        int totalNodes = nodeCount(tree);
        int index = 1;
        return checkCompleteness(tree,1,totalNodes) && checkMaxHeapProperty(tree);
    }
};