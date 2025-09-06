#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        string val;
        Node* next;
        Node* prev;

        Node(string val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class BrowserHistory {
public:
    Node* currPage;

    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
    }
    
    void visit(string url) {
        // Delete all next nodes of currPage
        if(currPage->next != NULL){
            currPage->next->prev = NULL; // Isolate 
            currPage->next = NULL;
        }
        // Insert new Node
        Node* newNode = new Node(url);
        newNode->prev = currPage;
        currPage->next = newNode;
        currPage = newNode;
    }
    
    string back(int steps) {
        while(currPage->prev != NULL && steps != 0){
            currPage = currPage->prev;
            steps -= 1;
        }
        return currPage->val;
    }
    
    string forward(int steps) {
        while(currPage->next != NULL && steps != 0){
            currPage = currPage->next;
            steps -= 1;
        }

        return currPage->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */