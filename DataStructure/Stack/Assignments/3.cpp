#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
  
    int bruteForce(vector<vector<int>>& M, int n) {
        int rowWithAllZeroes = -1;
        // Find whethere there is a row with allzeroes => Meaning tat person dont know anyone
        for(int i=0;i<n;i++){
            int j=0;
            for(;j<n;j++){
                if(M[i][j] != 0){
                    break;
                }
            }
            if(j >= n){
                rowWithAllZeroes = i;
                break;
            }
        }
        
        if(rowWithAllZeroes == -1){
            return -1;// No celebrity
        }else{
            // Checking if everyone else know that person(rowWithAllZeroes Person)
            for(int i=0;i<n;i++){
                if(i == rowWithAllZeroes){
                    continue;
                }
                
                if(M[i][rowWithAllZeroes] != 1){
                    return -1;
                }
            }
            return rowWithAllZeroes;
        }
    }

    int celebrity(vector<vector<int> >& M, int n) {
        //return bruteForce(M,n);
    }
};