#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    // Transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<matrix[i].size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // Mirror image
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<matrix[i].size()/2;j++){
    //         swap(matrix[i][j],matrix[i][n-j-1]);
    //     }
    // }

    // reverse each row
    for(int i = 0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}