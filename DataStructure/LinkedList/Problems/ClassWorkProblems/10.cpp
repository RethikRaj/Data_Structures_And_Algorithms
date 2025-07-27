#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // step1 : swap node->val with node->next->val
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;

        // step2:
        ListNode* forward = node->next;
        node->next = node->next->next;
        delete forward;
    }
};
