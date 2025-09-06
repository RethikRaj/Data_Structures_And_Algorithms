#include <bits/stdc++.h>
using namespace std;

void printMiddle(stack<int> &s,int count){
    // Base case
    if(count == 0){
        cout << s.top() << endl;
        return;
    }

    // 1 case me solve ,remaining recursion will solve
    int topEle = s.top();
    s.pop();

    printMiddle(s,count-1);

    s.push(topEle);

}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int count = s.size()/2;
    printMiddle(s,count);
}