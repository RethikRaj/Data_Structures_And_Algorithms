#include <iostream>
#include <vector>

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int rows = mat.size();
    vector<int> ans(2); // I initialised with 2 size just because in ques given 2 values needed. without initailising also you can do just use push_back at last.

    int rowWithMaxOnes = INT_MIN;
    int maxOnes = INT_MIN;

    for(int i=0;i<rows;i++){
        int numberOfOnes = 0;
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j] == 1){
                numberOfOnes++;
            }
        }
        if(numberOfOnes > maxOnes){
            maxOnes = numberOfOnes;
            rowWithMaxOnes = i;
        }
    }

    ans[0] = rowWithMaxOnes;
    ans[1] = maxOnes;

    return ans;
}
