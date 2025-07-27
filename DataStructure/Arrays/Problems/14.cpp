#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int>& v){
    int index = 0; // looping variable to traverse the array.
    int negativeElementPos = 0; //  denotes the position where can i store negative element
    while(index < v.size()){
        if(v[index] < 0){
            swap(v[index],v[negativeElementPos]);
            negativeElementPos++;
        }
        index++;
    }
}

void printVector(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    cout << endl;
}

int main(){
    vector<int> v = {23,-7,12,-10,-11,40,60};
    rearrange(v);
    printVector(v);
    return 0;
}