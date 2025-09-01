#include <iostream>
#include <vector>

using namespace std;

class Node{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
// Method 1 : store inorder and do binary search
// Method 2 : Traverse in inorder ....

// Method 3 : ITERATIVE WAY
class Solution1 {
  public:
    Node* findInorderPre(Node* root, int key){
        Node* curr = root;
        Node* IP = NULL;
        while(curr != NULL){
            if(curr->data < key){
                // update IP and then go right
                IP = curr;
                curr = curr->right;
            }else {
                curr = curr->left;
            }
        }
        return IP;
    }
    
    Node* findInorderSucc(Node* root, int key){
        Node* curr = root;
        Node* IS = NULL;
        while(curr != NULL){
            if(curr->data > key){
                IS = curr;
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        return IS;
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        
        ans.push_back(findInorderPre(root, key));
        ans.push_back(findInorderSucc(root, key));
        return ans;
    }
};

// Method 3 : RECURSIVE WAY
class Solution {
  public:
    void solution(Node* root, int &key, Node* &IP, Node* &IS){
        if(root == NULL) return;
        if (root->data > key){
            IS = root;
            solution(root->left, key, IP, IS);
        }else if(root->data < key){
            IP = root;
            solution(root->right, key, IP, IS);
        }else{
            solution(root->left, key , IP , IS);
            solution(root->right, key, IP, IS);
        }
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        if (root == NULL) return ans;
        
        Node* IP = NULL;
        Node* IS = NULL;
        solution(root, key, IP, IS);
        
        ans.push_back(IP);
        ans.push_back(IS);
        return ans;
    }
};