#include <iostream>
using namespace std;

int main(){

    int totalRows;
    cin >> totalRows;

    // Method 1: (Full pyramid + Half pyramid)
    // int num = totalRows/2;
    // // Full pyramid
    // for(int i=0;i<num;i++){
    //     // spaces
    //     for(int j=0;j<num-i-1;j++){
    //         cout << " ";
    //     }
    //     // stars & space
    //     for(int j=0;j<i+1;j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // // Inverted full pyramid
    // for(int i=0;i<num;i++){
    //     // spaces
    //     for(int j=0;j<i;j++){
    //         cout << " ";
    //     }
    //     // stars & space
    //     for(int j=0;j<num-i;j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // Method 2 : 
    int n = totalRows/2;
    for(int i=0;i<totalRows;i++){
        // first totalRows/2 rows
        if(i < n){
            // space
            for(int j=0;j<n-i-1;j++){
                cout << " ";
            }
            // star and space
            for(int j=0;j<i+1;j++){
                cout << "* ";
            }
        }
        else{
            // space
            for(int j=0;j<i-n;j++){
                cout << " ";
            }
            // stars & space
            for(int j=0;j<totalRows-i;j++){
                cout << "* ";
            }
        }
        cout << endl;
    }
    
}