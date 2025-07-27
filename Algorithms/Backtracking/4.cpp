#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    bool isSafe(vector<vector<char>>& board, string &word,int row,int col,int index,vector<vector<bool>> &visited){
        // check out of bounds
        if(row <0 || col <0 || row>=board.size() || col>= board[0].size()){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        if(visited[row][col] == true){
            return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, string &word,int row,int col,int index,vector<vector<bool>> &visited){
        // Base case
        if(index == word.size()){
            return true;
        }
        // 1 case me solve remaining recursion takes care
        // U, L , D , R
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,-1,0,1};
        bool ans = false;

        for(int i=0;i<4;i++){
            int newRowIndex = row + deltaX[i];
            int newColIndex = col + deltaY[i];
            if(isSafe(board,word,newRowIndex,newColIndex,index,visited)){
                visited[newRowIndex][newColIndex] = true;
                ans = solve(board,word,newRowIndex,newColIndex,index+1,visited);
                // Backtrack
                visited[newRowIndex][newColIndex] = false;

                if(ans == true){
                    return true;
                }
            }
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
       

        vector<vector<bool>> visited(m,vector<bool>(n,false));


        // starting point can be any cell
        bool ans = false;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col] == word[0]){
                    visited[row][col] = true;
                    ans = solve(board,word,row,col,1,visited);
                    visited[row][col] = false;
                }

                if(ans == true){
                    return true;
                }
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    bool isSafe(vector<vector<char>>& board, string &word,int row,int col,int index,vector<vector<bool>> &visited){
        // check out of bounds
        if(row <0 || col <0 || row>=board.size() || col>= board[0].size()){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        if(visited[row][col] == true){
            return false;
        }

        return true;
    }

    void solve(vector<vector<char>>& board, string &word,int row,int col,int index,vector<vector<bool>> &visited,bool &ans){
        // Base case
        if(index == word.size()-1){
            ans = true;
            return;
        }
        // 1 case me solve remaining recursion takes care
        // U, L , D , R
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int newRowIndex = row + deltaX[i];
            int newColIndex = col + deltaY[i];
            if(isSafe(board,word,newRowIndex,newColIndex,index+1,visited)){
                visited[newRowIndex][newColIndex] = true;
                solve(board,word,newRowIndex,newColIndex,index+1,visited,ans);
                // Backtrack
                visited[newRowIndex][newColIndex] = false;   
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        // starting point can be any cell
        bool ans = false;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col] == word[0]){
                    visited[row][col] = true;
                    solve(board,word,row,col,0,visited,ans);
                    visited[row][col] = false;
                }

                if(ans == true){
                    return true;
                }
            }
        }
        return ans;
    }
};

