#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// inplace solution that is without creating new nodes
// method 1 : Reverse inorder
class Solution1 {
  public:
    
    void solve(Node* root,Node* &head){
        // base case
        if(root == NULL){
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        // R
        solve(root->right,head);
        // Now right sub tree is converted to linked list and head points to that head of the right LL.
        // N
        if(head != NULL){
            head->left = root;
        }
        root->right = head;
        // Now (curr_node + its right sub tree) is converted to LL and thus need to update head to curr_node
        head = root;
        // L
        solve(root->left,head);
    }
  
  
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        solve(root,head);
        return head;
    }
};

// inplace solution that is without creating new nodes
// method 2 : Inorder 

class Solution2 {
  public:
    
    void solve(Node* root,Node* &head,Node* &tail){
        // base case
        if(root == NULL){
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        // L
        solve(root->left,head,tail);
        // Now left LL is done and tail points to the last node of the left LL
        // N
        // Connect 
        if (tail != NULL){
            tail->right = root;
        }
        root->left = tail;
        // Update head and tail
        if(head == NULL){
            head = tail = root;
        }else{
            tail = root;
        }
        // R
        solve(root->right,head,tail);
    }
  
  
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* tail = NULL;
        solve(root,head,tail);
        return head;
    }
};


// out of place solution => Waste
class Solution3 {
  public:
  
    void storeInOrder(Node* root,vector<int> &inorder){
        if(root == NULL){
            return;
        }else{
            storeInOrder(root->left,inorder);
            inorder.push_back(root->data);
            storeInOrder(root->right,inorder);
        }
    }
  
  
    Node* insertInDLL(Node* head,Node* &tail,int val){
        if(head == NULL){
            Node* newNode = new Node(val);
            tail = newNode;
            return newNode;
        }
        
        Node* newNode = new Node(val);
        newNode->left = tail;
        tail->right = newNode;
        tail = newNode;
        return head;
    }
  
    Node* bToDLL(Node* root) {
        vector<int> inorder;
        storeInOrder(root,inorder);
        
        Node* head = NULL;
        Node* tail = NULL;
        for(int i=0;i<inorder.size();i++){
            head = insertInDLL(head,tail,inorder[i]);
        }
        
        
        return head;
    }
};