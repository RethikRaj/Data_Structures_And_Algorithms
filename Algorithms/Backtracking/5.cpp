#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int row,int col,char digit){
        // Row check
        // Why checking full row => because previously some digits are filled in question
        for(int i=0;i<board[0].size();i++){
            if(board[row][i] == digit){
                return false;
            }
        }

        // Column check
        for(int i=0;i<board.size();i++){
            if(board[i][col] == digit){
                return false;
            }
        }

        // 3*3 subgrid check
        int subgridRow = row%3;
        int subgridCol = col%3;
        int subgridstartRowIndex = row-subgridRow;
        int subgridstartColIndex = col-subgridCol;

        for(int i=subgridstartRowIndex;i<subgridstartRowIndex+3;i++){
            for(int j=subgridstartColIndex;j<subgridstartColIndex+3;j++){
                if(board[i][j] == digit){
                    return false;
                }
            }
        }

        // here reached => its safe
        return true;
    }

    bool solve(vector<vector<char>>& board,int row,int col){
        if(row >= board.size()){
            // all cells filled => solved
            return true;
        }

        // 1 case me solve remaining recursion handles
        if(board[row][col] == '.'){
            for(char i='1';i<='9';i++){
                if(isSafe(board,row,col,i)){
                    // place the digit
                    board[row][col] = i;

                    bool ans = false;
                    // recursion
                    if(col == board[0].size()-1){
                        ans = solve(board,row+1,0);
                    }else{
                        ans = solve(board,row,col+1);
                    }

                    // Backtracking
                    // two cases possible -> board is solved using this digit or board is not solved using this digit => need to know board solved or not => make function returntype as bool
                    // if board solved by this digit then no need of next call
                    if(ans == true){
                        return true;
                    }else{
                        // board is not solved by this digit
                        board[row][col] = '.';
                    }
                }
            }
            // you reach here only when after using all digits you get no solution => we may have placed digit wrong before
            return false;
        }
        else{
            bool ans = false;
            if(col == board[0].size()-1){
                ans = solve(board,row+1,0);
            }else{
                ans = solve(board,row,col+1);
            }

            return ans;
        }
    }


    void solveSudoku(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        solve(board,row,col);
    }
};