#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isAllRotten(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return false;
                }
            }
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        queue<pair<int,int>> q;

        // initial state
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        // main logic
        int time = 0;
        while(!isAllRotten(grid) && !(q.empty())){
            queue<pair<int,int>> temp;
            while(!q.empty()){
                auto frontCell = q.front();
                int x = frontCell.first;
                int y = frontCell.second;
                q.pop();
                // make all adjacent rotten
                // UP
                if(x-1 >= 0 && grid[x-1][y] != 2 && grid[x-1][y] != 0){
                    grid[x-1][y] = 2;
                    temp.push({x-1,y});
                }
                // DOWN
                if(x+1 < R && grid[x+1][y] != 2 && grid[x+1][y] != 0){
                    grid[x+1][y] = 2;
                    temp.push({x+1,y});
                }
                // LEFT
                if(y-1 >= 0 && grid[x][y-1] != 2 && grid[x][y-1] != 0){
                    grid[x][y-1] = 2;
                    temp.push({x,y-1});
                }
                // RIGHT
                if(y+1 < C && grid[x][y+1] != 2 && grid[x][y+1] != 0){
                    grid[x][y+1] = 2;
                    temp.push({x,y+1});
                }
            }
            swap(temp,q);
            time++;
        }

        if(isAllRotten(grid)){
            return time;
        }else{
            return -1;
        }
    }
};