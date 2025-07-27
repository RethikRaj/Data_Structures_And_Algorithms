#include <iostream>
#include <stack>

using namespace std;

bool checkSorted(stack<int> &s,int element1){
    // Base case
    if(s.empty()){
        // stack is compared fully and it is sorted
        return true;
    }

    // 1 case me solve remaining recursion will solve
    // 1 case -> check elem1 with top
    int element2 = s.top();
    s.pop();
    if(element2 < element1){
        // check further => RECURSION 
        bool recKaAns = checkSorted(s,element2);
        // Backtrack
        s.push(element2);
        return recKaAns;
    }else{
        return false;
    }
}



int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int ele1 = INT_MAX;
    cout << checkSorted(s,ele1);
    return 0;
}