#include<iostream>
using namespace std;

int main(){
    // 2D array-> Stack memory
    int arr[3][4] = {
        {10,20,30,40},
        {50,60,70,80},
        {90,100,110,120}
    };

    // 2D array -> Heap Memory
    int rowCount = 4;
    int colCount = 5;
    int** brr = new int*[rowCount];
    for(int i=0;i<rowCount;i++){
        brr[i] = new int[colCount];
    }

    // Deallocating
    
    for(int i=0; i<4; i++) {
        delete[] arr[i];
    }

    // Accesing
    //taking input 
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cin >> brr[i][j];
        }
    }

    cout << endl << "Printing the 2D array " << endl;
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cout <<  brr[i][j] << ' ';
        }
        cout << endl;
    }

    


    
    return 0;
}