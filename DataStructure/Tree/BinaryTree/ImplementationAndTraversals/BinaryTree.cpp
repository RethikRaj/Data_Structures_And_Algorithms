#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int val){
            this->data = val;
            left = NULL;
            right = NULL;
        }
};

Node* createTree(vector<int> &arr,int &index){
    int val = arr[index];
    // base case
    if(val == -1){
        return NULL;
    }
    else{
        // now we are having valid data
        // 1 case me solve remaining recursion
        // step1 : create node
        Node* newNode = new Node(val);
        // step2 : add left child
        index++;
        newNode->left = createTree(arr,index);
        // step3: add right child
        index++;
        newNode->right = createTree(arr,index);
        return newNode;
    }
}

void preOrder(Node* root){
    if(root != NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    // Traverse the left subtree
    inOrder(root->left);
    // print curr node
    cout << root->data << " ";
    // Traverse the right subtree
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    // Traverse the left subtree
    postOrder(root->left);
    // Traverse the right subtree
    postOrder(root->right);
    // print curr node
    cout << root->data << " ";
}

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    // initial state
    int level = 0;
    q.push(root);
    q.push(NULL); // to differentiiate levels

    while(!q.empty()){
        // pop curr node and if not null then print and add childs, else add new line => new level
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            // insert a new line
            cout << endl;
        }else{
            if(front->left != NULL){
                
            }
        }

    }
}


int main(){
    Node* root;
    vector<int> arr = {10,50,40,-1,-1,-1,30,20,-1,-1,-1};
    int index = 0;
    root = createTree(arr,index);
    cout << "Printing Tree : ";
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    


    return 0;
}