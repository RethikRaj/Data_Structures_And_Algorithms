#include <iostream>
#include <vector>
using namespace std;

void printArrayRowWise(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printArrayColWise(int arr[][4],int row,int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    // creation
    int arr[4][5];

    // intialisation
    int brr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int crr[][4] = { // remaining intialised with zeroes
        {10,20,30},
        {},
        {}, 
        {}
    };

    // error
    //int drr[2][] = {};
    //int err[][] = {};

    // Printing 
    printArrayRowWise(crr,4,4);
    
    printArrayColWise(brr,3,4);


    // jagged array using vectors

    vector<vector<int>> v;
    vector<int> vec1(5,10);
    vector<int> vec2(10,20);
    vector<int> vec3(2,30);
    vector<int> vec4(20,40);

    v.push_back(vec1);
    v.push_back(vec2);
    v.push_back(vec3);
    v.push_back(vec4);

    return 0;
}