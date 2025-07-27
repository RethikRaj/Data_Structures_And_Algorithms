#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    // Method 3 : SC :O(1)
    void method3(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    // mark ith row as zero
                    matrix[i][0] = 0;

                    // mark jth col as zero
                    if(j == 0){
                        col0 = 0;
                    }else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        // handling line A,B,C
        for(int i=m-1;i>=1;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // handling line D
        for(int col=n-1;col>=1;col--){
            if(matrix[0][0] == 0 || matrix[0][col]== 0){
                matrix[0][col] = 0;
            }
        }

        // handling line E
        for(int row = 0;row<m;row++){
            if(matrix[row][0] == 0 || col0 == 0){
                matrix[row][0] = 0;
            }
        }

    
    }





    void makeColZero(vector<vector<int>>& matrix,int col){
        // making col zero
        for(int i=0;i<matrix.size();i++){
            matrix[i][col] = 0;
        }
    }

    void makeRowZero(vector<vector<int>>& matrix,int row){
        // Making row zero
        for(int i=0;i<matrix[0].size();i++){
            matrix[row][i] = 0;
        }
    }

    // store rowZeroesPos and colZeroesPos separately => SC : O(m+n)
    void method2(vector<vector<int>>& matrix){
        int mRows = matrix.size();
        int nCols = matrix[0].size();

        unordered_set<int> rowZeroPos;
        unordered_set<int> colZeroPos;

        for(int i=0;i<mRows;i++){
            for(int j=0;j<nCols;j++){
                if(matrix[i][j] == 0){
                    rowZeroPos.insert(i);
                    colZeroPos.insert(j);
                }
            }
        }

        // Making rows and cols zero 
        // M-1 : TC : O(2(m*n))

        // unordered_set<int>::iterator it = rowZeroPos.begin();
        // while(it != rowZeroPos.end()){
        //     cout << *it << endl;
        //     makeRowZero(matrix,*(it));
        //     it++;
        // }
        // it = colZeroPos.begin();

        // while(it != colZeroPos.end()){
        //     makeColZero(matrix,*(it));
        //     it++;
        // }

        // Method2 :  // tc : O(m*n) // think about one element at a time so little bit easier
        for(int i=0;i<mRows;i++){
            for(int j=0;j<nCols;j++){
                if(rowZeroPos.count(i)==1 || colZeroPos.count(j) == 1){
                    matrix[i][j] = 0;
                }
            }
        }

    }

    // SC : O(m*n)
    void method1(vector<vector<int>>& matrix){
        int mRows = matrix.size();
        int nCols = matrix[0].size();

        vector<pair<int,int>> zeroesPos; // row -> col
        for(int i=0;i<mRows;i++){
            for(int j=0;j<nCols;j++){
                if(matrix[i][j] == 0){
                    cout << i << " " << j << endl;
                    zeroesPos.push_back(make_pair(i,j));
                }
            }
        }

        vector<pair<int,int>>::iterator it = zeroesPos.begin();
        while(it != zeroesPos.end()){
            int row = (*it).first;
            int col = (*it).second;
            makeRowZero(matrix,row);
            makeColZero(matrix,col);
            it++;
        }

        
    }

    void setZeroes(vector<vector<int>>& matrix) {
        //method1(matrix);
        method2(matrix);
    }
};