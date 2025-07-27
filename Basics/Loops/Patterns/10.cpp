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
        // 1st star
        cout << "*";
        // spaces
        for(int j=0;j<2*i-1;j++){
            cout << " ";
        }
        // 2nd star
        if(i != 0)
            cout << "*";
        
        cout << endl;
    }

    cout << "Method 2:" << endl;


    for(int i=0;i<num;i++){
        // spaces
        for(int j=0;j<num-i-1;j++){
            cout << " ";
        }
        // star & space
        for(int j=0;j<i+1;j++){
            // totalCols is i+1 => last col will be i
            if(j==0 || j==i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    
}