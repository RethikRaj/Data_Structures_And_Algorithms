#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;

    for(int i=0;i<num;i++){
        for(int j=0;j<num-i-1;j++){
            cout << " ";
        }
        for(int z=0;z<i+1;z++){
            cout << "* ";
        }
        cout << endl;
    }
}