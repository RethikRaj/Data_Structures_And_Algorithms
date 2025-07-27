#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number : " ;
    cin >> num;

    if(num > 0){
        cout << "+ve" << endl;
    }else if(num < 0){
        cout << "-ve" << endl;
    }else{
        cout << "zero" <<endl;
    }
}