#include <iostream>
using namespace std;

int main(){
    int ROWS;
    int COLS;
    cin >> ROWS >> COLS;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cout << "* ";
        }
        cout << endl;
    }
}
