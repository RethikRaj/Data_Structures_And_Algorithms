#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS helper function to traverse the connected component
    void solve(vector<vector<int>>& grid, int row, int col, int color, vector<vector<bool>> &visited) {
        // Mark the current cell as visited
        visited[row][col] = true;

        // Flag to decide whether this cell should be recolored
        bool shouldColor = false;

        // If this cell is on the boundary of the grid => it's a border cell
        if (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1) {
            shouldColor = true;
        }

        // Directions: UP, DOWN, LEFT, RIGHT
        vector<int> deltaX = {-1, 1, 0, 0};
        vector<int> deltaY = {0, 0, -1, 1};

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + deltaX[i];
            int newCol = col + deltaY[i];

            // Skip if out of bounds
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) {
                continue;
            }

            // Skip if already visited
            if (visited[newRow][newCol] == true) {
                continue;
            }

            // If the neighbor has a different color, current cell is a border
            if (grid[newRow][newCol] != grid[row][col]) {
                shouldColor = true;
            } else {
                // *Otherwise, continue DFS in the same connected component => Only call DFS inside same connected component
                solve(grid, newRow, newCol, color, visited);
            }
        }

        // After exploring neighbors, if this is a border cell → recolor it
        if (shouldColor) {
            grid[row][col] = color;
        }
    }

    // Main function to color the border of the connected component
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // Each grid cell is treated as a graph vertex
        int R = grid.size();
        int C = grid[0].size();

        // Keep track of visited cells
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Start DFS from the given (row, col) cell
        solve(grid, row, col, color, visited);

        // Return the updated grid
        return grid;
    }
};


// Method 2 : Without visited => Later