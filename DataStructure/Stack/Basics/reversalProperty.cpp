#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> s;
    string name = "RETHIK RAJ";

    // insertion of character into the stack
    for(int i=0;i<name.length();i++){
        s.push(name[i]);
    }

    // retrieval of characters from the stack-> we get reverse
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
