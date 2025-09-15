#include <bits/stdc++.h>
using namespace std;

// Can solve using both BFS, DFS


// Solution 1 : Using visited array => TC : O(n*m), SC : O(n*m)
class Solution {
public:
    // (row, col) represents a single Vertex
    void BFS(vector<vector<char>>& grid, int row, int col,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while(!q.empty()){
            pair<int,int> currVertex = q.front();
            q.pop();

            // add neighbours to queue => Neighbours are UP, DOWN, LEFT, RIGHT
            vector<int> deltaX = {-1, 1, 0, 0};
            vector<int> deltaY = {0, 0, -1, 1};
            for(int i = 0; i < 4;i++){
                int newRow = currVertex.first + deltaX[i];
                int newCol = currVertex.second + deltaY[i];

                // Method 2:
                if(newRow >= 0 && newRow < grid.size() && newCol >=0 && newCol < grid[0].size() && grid[newRow][newCol] == '1' && visited[newRow][newCol] == false){
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }

                // Method 1:

                // if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()){
                //     continue;
                // }

                // if(grid[newRow][newCol] == '0'){
                //     continue;
                // }

                // if(visited[newRow][newCol] == true){
                //     continue;
                // }

                // // Now grid[row][col] = 1 => valid unvisited neighbour push into queue
                // q.push({newRow, newCol});
                // visited[newRow][newCol] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // Each vertex is denoted by (x,y)

        int R = grid.size();
        int C = grid[0].size();
        int connectedComponents = 0;

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        
        for(int i=0;i < grid.size();i++){
            for(int j=0; j < grid[0].size();j++){
                // If not visited and land body
                if( !visited[i][j] && grid[i][j] == '1'){
                    BFS(grid, i, j, visited);
                    connectedComponents += 1;
                }
            }
        }

        return connectedComponents;
    }
};


// Solution 2 : Without using visited array.
// We mark visited by marking grid[row][col] = '0', dont use '-1' leetcode wont allow since it is a binary matrix
class Solution {
public:
    // (row, col) represents a single Vertex
    void BFS(vector<vector<char>> &grid, int row, int col){
        queue<pair<int,int>> q;

        // Add vertex to queue
        q.push({row, col});
        // Mark the vertex as visited
        grid[row][col] = '0';

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            // visit neighbours
            vector<int> deltaX = {-1, 1, 0, 0};
            vector<int> deltaY = {0, 0, -1, 1};
            for(int i=0;i<4;i++){
                int newRow = curr.first + deltaX[i];
                int newCol = curr.second + deltaY[i];

                
                // Check valid index
                if(newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()){
                    continue;
                }

                // !IMP: Check water body and check visited => both done using same check
                if(grid[newRow][newCol] == '0'){
                    continue;
                }
                // Unvisited and valid index => Push to queue and mark it as visited
                q.push({newRow, newCol});
                grid[newRow][newCol] = '0';
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int connectedComponents = 0;

        for(int i = 0; i < R;i++){
            for(int j = 0; j < C;j++){
                // check water body and check already visited
                if(grid[i][j] == '0'){
                    continue;
                }

                // land body and unvisited
                BFS(grid, i, j);
                connectedComponents += 1;
            }
        }
        return connectedComponents;
    }
};