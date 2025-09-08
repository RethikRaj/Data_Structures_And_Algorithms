#include <bits/stdc++.h>
using namespace std;


// Solution 1 : TC : O(n*m), SC : O(n*m)=> Due to visited array
class Solution {
public:
    void solveUsingRecursion(vector<vector<int>>& image, int row, int col, int color, int &originalColor, vector<vector<bool>> &visited){

        // base case
        if(image[row][col] != originalColor){
            return;
        }

        // 1 case me solve remaining recursion will handle
        image[row][col] = color;
        visited[row][col] = true;

        // UP, DOWN, LEFT, RIGHT
        vector<int> deltaX = {-1, 1, 0, 0};
        vector<int> deltaY = {0, 0, -1, 1};

        for(int i=0; i < 4;i++){
            int newRow = row + deltaX[i];
            int newCol = col + deltaY[i];
            if(newRow < 0 || newRow >= image.size() || newCol < 0 || newCol >= image[0].size() || visited[newRow][newCol] == true){
                continue;
            }
            solveUsingRecursion(image, newRow, newCol, color, originalColor, visited);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        solveUsingRecursion(image, sr, sc, color, originalColor, visited);
        return image;
    }
};

// Solution 2 : IMPORTANT : WITHOUT VISITED 
class Solution {
public:
    void solveUsingRecursion(vector<vector<int>>& image, int row, int col, int color, int &originalColor) {
        // base case
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()){
            return;
        }

        if(image[row][col] != originalColor){
            return;
        }

        // paint the pixel
        image[row][col] = color;

        // directions: UP, DOWN, LEFT, RIGHT
        vector<int> deltaX = {-1, 1, 0, 0};
        vector<int> deltaY = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++){
            int newRow = row + deltaX[i];
            int newCol = col + deltaY[i];
            solveUsingRecursion(image, newRow, newCol, color, originalColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        // !avoid infinite loop
        if(originalColor == color){
            return image;
        } 
        solveUsingRecursion(image, sr, sc, color, originalColor);
        return image;
    }
};
