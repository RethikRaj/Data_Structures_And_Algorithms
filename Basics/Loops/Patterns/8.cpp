#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;

    for(int i=0;i<num;i++){
        // spaces
        for(int j=0;j<i;j++){
            cout << " ";
        }
        // stars & space
        for(int j=0;j<num-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
    
}