#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next, *prev;
    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Solution{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        vector<pair<int,int>> ans;
        if(head == NULL){
            return ans;
        }
        // find tail
        Node* right = head;
        while(right->next != NULL){
            right = right->next;
        }
        Node* left = head;
        
        // Two pointer approach
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                ans.push_back(make_pair(left->data,right->data));
                left = left->next;
                right = right->prev;
            }
            else if(sum < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        return ans;
    }
};