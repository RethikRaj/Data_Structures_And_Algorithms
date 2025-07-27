#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Row wise placing

// Method1 : isSafe method takes O(n) time

class Solution1{
public:
    bool isSafe(vector<string> &chessBoard,int n,int rowIndex,int colIndex){
        // Check Upper column
        for(int i=rowIndex-1;i>=0;i--){
            if(chessBoard[i][colIndex] == 'Q'){
                return false;
            }
        }

        // Check diagonal
        // Upper left
        for(int i=rowIndex-1,j=colIndex-1; i>=0 && j>=0;i--,j--){
            if(chessBoard[i][j] == 'Q'){
                return false;
            }
        }

        // Upper right
        for(int i=rowIndex-1,j=colIndex+1; i >= 0  && j < n;i--,j++){
            if(chessBoard[i][j] == 'Q'){
                return false;
            }
        }

        // now here its safe
        return true;
    }


    void solve(vector<vector<string>> &ans,vector<string> &chessBoard,int n,int rowIndex){
        // Base case 
        if(rowIndex == n){
            ans.push_back(chessBoard);
            return;
        }

        // 1 case me solve remaining recursion will handle
        // 1 case -> colIndex = 0 to n-1 => that is I have rowIndex , in that row , at which column should i place my queen 
        for(int col = 0;col < n;col++){
            if(isSafe(chessBoard,n,rowIndex,col)){
                // Place queen
                chessBoard[rowIndex][col] = 'Q';
                // recursive call
                solve(ans,chessBoard,n,rowIndex+1);
                // Backtrack => Remove queen
                chessBoard[rowIndex][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // initialize chessBoard with '.'
        // create a string "... " of n length
        string s = "";
        for(int i=0;i<n;i++){
            s += ".";
        }
        vector<string> chessBoard(n,s);

        int rowIndex = 0;
        solve(ans,chessBoard,n,rowIndex);
        return ans;
    }
};


// Method 2 : isSafe method takes O(1) time
class Solution {
public:
    unordered_map<int,bool> colCheck;
    unordered_map<int,bool> leftDiagonalCheck;
    unordered_map<int,bool> rightDiagonalCheck;
    bool isSafe(vector<string> &chessBoard,int n,int rowIndex,int colIndex){
        // colCheck
        if(colCheck[colIndex] == true){
            return false;
        }
        if(leftDiagonalCheck[rowIndex-colIndex] == true){
            return false;
        }
        if(rightDiagonalCheck[rowIndex+colIndex] == true){
            return false;
        }

        // now here its safe
        return true;
    }


    void solve(vector<vector<string>> &ans,vector<string> &chessBoard,int n,int rowIndex){
        // Base case 
        if(rowIndex == n){
            ans.push_back(chessBoard);
            return;
        }

        // 1 case me solve remaining recursion will handle
        // 1 case -> colIndex = 0 to n
        for(int colIndex = 0;colIndex < n;colIndex++){
            if(isSafe(chessBoard,n,rowIndex,colIndex)){
                // Place queen
                chessBoard[rowIndex][colIndex] = 'Q';
                colCheck[colIndex] = true;
                leftDiagonalCheck[rowIndex-colIndex] = true;
                rightDiagonalCheck[rowIndex+colIndex] = true;
                // recursive call
                solve(ans,chessBoard,n,rowIndex+1);
                // Backtrack => Remove queen
                chessBoard[rowIndex][colIndex] = '.';
                colCheck[colIndex] = false;
                leftDiagonalCheck[rowIndex-colIndex] = false;
                rightDiagonalCheck[rowIndex+colIndex] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        

        // initialize chessBoard with '.'
        // create a string "... " of n length
        string s = "";
        for(int i=0;i<n;i++){
            s += ".";
        }
        vector<string> chessBoard(n,s);

        int rowIndex = 0;
        solve(ans,chessBoard,n,rowIndex);
        return ans;
    }
};




