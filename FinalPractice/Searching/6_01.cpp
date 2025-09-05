// Search a 2D Matrix

#include <bits/stdc++.h>
using namespace std;

// Optimized Solution 1 :
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        int C = matrix[0].size();

        int startRow = 0;
        int endRow = R - 1;
        while(startRow < endRow){
            int midRow = startRow + (endRow - startRow)/2;
            if(target < matrix[midRow][C - 1]){
                endRow = midRow;
            }else if(target > matrix[midRow][C - 1]){
                startRow = midRow + 1;
            }else{
                return true;
            }
        }

        if(startRow == endRow){
            // apply binarySearch
            int startCol = 0;
            int endCol = C - 1;

            while(startCol <= endCol){
                int midCol = startCol + (endCol - startCol)/2;

                if(target > matrix[startRow][midCol]){
                    startCol = midCol + 1;
                }else if(target < matrix[startRow][midCol]){
                    endCol = midCol - 1;
                }else{
                    return true;
                }
            }
        }

        return false;
    }
};

// Optimized solution 2 :
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        int C = matrix[0].size();

        int low = 0;
        int high = R*C - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int midRowIndex = mid / C;
            int midColIndex = mid % C;

            if(matrix[midRowIndex][midColIndex] == target){
                return true;
            }else if(matrix[midRowIndex][midColIndex] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }

        }

        return false;
        
    }
};