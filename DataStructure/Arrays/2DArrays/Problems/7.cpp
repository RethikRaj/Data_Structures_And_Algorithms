#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int startRow = 0;
        int startCol = 0;
        int endRow = m-1;
        int endCol = n-1;

        while(startRow <= endRow && startCol <= endCol){
            // 1 spiral print
            // top row
            for(int col = startCol;col <= endCol;col++){
                // cout << matrix[startRow][col] << " ";  
                ans.push_back(matrix[startRow][col]);
            }
            // rightMostCol
            for(int row = startRow+1;row <= endRow;row++){
                //cout << matrix[row][endCol] << " ";
                ans.push_back(matrix[row][endCol]);  
            }
            // bottomRow
            if(startRow != endRow){ // to differentiate top Row and bottom Row => to avoid repetition
                for(int col = endCol-1;col>=startCol;col--){
                    //cout << matrix[endRow][col] << " ";
                    ans.push_back(matrix[endRow][col]);
                }
            }
            // leftMost col
            if(startCol != endCol){ // to differentiate righMost and leftMostCol => to avoid repetition
                for(int row = endRow-1;row >= startRow+1;row--){
                    //cout << matrix[row][startCol] << " ";
                    ans.push_back(matrix[row][startCol]);
                }
            }

            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
        return ans;
    }


    // Method 2 : (Just a different way of writing code)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int startRow = 0;
        int startCol = 0;
        int endRow = m-1;
        int endCol = n-1;
        int count = 0;
        int totalElements = m*n;

        while(count < totalElements){
            // 1 spiral print
            // top row
            for(int col = startCol;col <= endCol && count < totalElements;col++){
                // cout << matrix[startRow][col] << " ";  
                ans.push_back(matrix[startRow][col]);
                count++;
            }
            startRow++;

            // rightMostCol
            for(int row = startRow;row <= endRow && count < totalElements;row++){
                //cout << matrix[row][endCol] << " ";
                ans.push_back(matrix[row][endCol]);  
                count++;
            }
            endCol--;

            // bottomRow
            for(int col = endCol;col>=startCol && count < totalElements;col--){
                //cout << matrix[endRow][col] << " ";
                ans.push_back(matrix[endRow][col]);
                count++;
            }
            
            endRow--;
            // leftMost col
            for(int row = endRow;row >= startRow && count < totalElements;row--){
                //cout << matrix[row][startCol] << " ";
                ans.push_back(matrix[row][startCol]);
                count++;
            }
            
            startCol++;
        }
        return ans;
    }
};