#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;

    // Push elements in queue into stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    // retrieve elements from stack and push it into queue.
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void reverseQueueRecursive(queue<int> &q){
    if(q.empty()){
        return;
    }
    // 1 case
    int frontEle = q.front();
    q.pop();
    // recursion
    reverseQueueRecursive(q);
    // Backtracking
    q.push(frontEle);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    //reverseQueue(q);
    reverseQueueRecursive(q);

    // printing
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}