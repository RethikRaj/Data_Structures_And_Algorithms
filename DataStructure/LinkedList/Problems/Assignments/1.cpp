#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *getListAfterDeleteOperation(Node *head, int n, int m){
	Node* ptr = head;
	Node* prev = NULL;
	while(ptr != NULL){
		// Move ptr m times
		for(int i=0;i<m;i++){
			prev = ptr;
			ptr = ptr->next;
			// if remaining LL has <= m nodes,then while traversing ptr get to null.
			if(ptr == NULL){
				return head;
			}
		}
		// Delete : ptr points the node to be deleted and prev points to node before that
		if(prev != NULL){
			// Delete n nodes one by one
			for(int i=0;i<n;i++){
				prev->next = ptr->next;
				ptr->next = NULL;
				delete ptr;
				// updating ptr 
				ptr =prev->next;
				if(ptr == NULL){
					// this case becomes true when there are <= n nodes to delete
					return head;
				}
			}
		}
	}
	return head;
}