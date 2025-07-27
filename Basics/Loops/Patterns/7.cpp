#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    for(int i=0;i<num;i++){
        // spaces
        for(int j=0;j<num-i-1;j++){
            cout << " ";
        }
        // stars & space
        for(int j=0;j<i+1;j++){
            cout << "* ";
        }
        cout << endl;
    }
    
}