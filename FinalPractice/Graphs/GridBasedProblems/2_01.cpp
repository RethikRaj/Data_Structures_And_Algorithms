#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BFS(vector<vector<char>>& grid, pair<int,int> srcVertex,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push(srcVertex);
        visited[srcVertex.first][srcVertex.second] = true;

        while(!q.empty()){
            pair<int,int> currVertex = q.front();
            q.pop();

            // add neighbours to queue => Neighbours are UP, DOWN, LEFT, RIGHT
            vector<int> deltaX = {-1, 1, 0, 0};
            vector<int> deltaY = {0, 0, -1, 1};
            for(int i = 0; i < 4;i++){
                int row = currVertex.first + deltaX[i];
                int col = currVertex.second + deltaY[i];

                if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
                    continue;
                }

                if(grid[row][col] == '0'){
                    continue;
                }

                if(visited[row][col] == true){
                    continue;
                }

                // Now grid[row][col] = 1 => valid unvisited neighbour push into queue
                q.push(make_pair(row, col));
                visited[row][col] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // Each vertex is denoted by (x,y)

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int numberOfIslands = 0;
        
        for(int i=0;i < grid.size();i++){
            for(int j=0; j < grid[0].size();j++){
                if( !visited[i][j] && grid[i][j] == '1'){
                    BFS(grid, make_pair(i, j), visited);
                    numberOfIslands += 1;
                }
            }
        }

        return numberOfIslands;
    }
};