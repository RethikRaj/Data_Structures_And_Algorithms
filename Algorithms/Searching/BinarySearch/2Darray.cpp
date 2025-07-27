#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R = matrix.size();
    int C = matrix[0].size();
    int n = R*C;
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        int rowIndex = mid/C;
        int colIndex = mid%C;
        if(matrix[rowIndex][colIndex] == target){
            return true;
        }else if(matrix[rowIndex][colIndex] < target){
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}