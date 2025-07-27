#include <iostream>
#include <stack>

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
