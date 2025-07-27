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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n,-1));

        int topRow = 0;
        int rightCol = n-1;
        int bottomRow = m-1;
        int leftCol = 0;

        ListNode* ptr = head;

        while(ptr != NULL){
            // top row
            for(int j=leftCol;j<=rightCol;j++){
                if(ptr != NULL){
                    ans[topRow][j] = ptr->val;
                    ptr = ptr->next;
                }
            }

            // rightCol
            for(int i=topRow+1;i<=bottomRow;i++){
                if(ptr != NULL){
                    ans[i][rightCol] = ptr->val;
                    ptr = ptr->next;
                }
            }

            // bottom row
            for(int j=rightCol-1;j>=leftCol;j--){
                if(ptr != NULL){
                    ans[bottomRow][j] = ptr->val;
                    ptr = ptr->next;
                }
            }

            // leftCol
            for(int i = bottomRow-1;i >= topRow+1;i--){
                if(ptr != NULL){
                    ans[i][leftCol] = ptr->val;
                    ptr = ptr->next;
                }
            }

            topRow++;
            rightCol--;
            bottomRow--;
            leftCol++;
        }
        return ans;
    }
};
