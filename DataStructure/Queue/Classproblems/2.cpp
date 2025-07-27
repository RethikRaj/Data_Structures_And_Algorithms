#include <iostream>
#include <queue>
#include <stack>

using namespace std;



void reverseInKGroup(queue<int> &q,int k,int pendingElementsToReverse){
    // Base case:
    if(pendingElementsToReverse < k){
        // pop from queue and insert as it is without reversing
        for(int i=0;i<pendingElementsToReverse;i++){
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        return;
    }

    // 1 case me solve remaining recursion
    // 1 case -> Step1: Insert k eleents into stack then insert at back in queue
    stack<int> s;
    // Insert k elements in stack
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    // Insert into queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // Recursion
    reverseInKGroup(q,k,pendingElementsToReverse-k);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    //q.push(100);
    //q.push(110);

    int k = 3;
    int pendingElementsToReverse = q.size();
    reverseInKGroup(q,k,pendingElementsToReverse);

    // printing
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

