#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &m,int n,int rowIndex,int colIndex,vector<vector<bool>> &visited){
    if(rowIndex < 0 || colIndex < 0 || rowIndex >= n || colIndex >= n){
        // Out of Bounds
        return false;
    }
    if(m[rowIndex][colIndex] == 0){
        // blocked space
        return false;
    }
    if(visited[rowIndex][colIndex] == true){
        // already visited
        return false;
    }

    // now it is safe
    return true;
}

void solve(vector<vector<int>> &m,int n,int rowIndex,int colIndex,string path,vector<string> &paths,vector<vector<bool>> &visited){

    // base case
    if(rowIndex == n-1 && colIndex == n-1){
        // rat reached destination
        paths.push_back(path);
        return;
    }

    // 1 case me solve remaining recursion solve karege
    // 1 case -> UP , LEFT , DOWN , RIGHT

    // Idea 4 : Create a class with (-1,0,'U'),(0,-1,'L'),..
    // Method 3 : short code
    int deltaX[] = {-1,0,1,0};
    int deltaY[] = {0,-1,0,1};
    char movement[] = {'U','L','D','R'};

    for(int i=0;i<4;i++){
        int newRowIndex = rowIndex + deltaX[i];
        int newColIndex = colIndex + deltaY[i];
        if(isSafe(m,n,newRowIndex,newColIndex,visited)){
            visited[newRowIndex][newColIndex] = true;
            // path.push_back(movement[i]);
            solve(m,n,newRowIndex,newColIndex,path+movement[i],paths,visited);
            // backtracking
            // path.pop_back;
            visited[newRowIndex][newColIndex] = false;
        }
    }


    // Method 2:

    // for(int i=0;i<4;i++){
    //     int newRowIndex = rowIndex;
    //     int newColIndex = colIndex;
    //     string toAdd = "";
    //     if(i==0){ // UP
    //         newRowIndex = rowIndex -1;
    //         newColIndex = colIndex;
    //         toAdd = "U";
    //     }else if(i==1){ // left
    //         newRowIndex = rowIndex;
    //         newColIndex = colIndex-1;
    //         toAdd = "L";
    //     }else if(i==2){//down
    //         newRowIndex = rowIndex+1;
    //         newColIndex = colIndex;
    //         toAdd = "D";
    //     }else if(i==3){//right
    //         newRowIndex = rowIndex;
    //         newColIndex = colIndex+1;
    //         toAdd = "R";
    //     }
    //     if(isSafe(m,n,newRowIndex,newColIndex,visited)){
    //         visited[newRowIndex][newColIndex] = true;
    //         // path.push_back(toAdd);
    //         solve(m,n,newRowIndex,newColIndex,path+toAdd,paths,visited);
    //         // backtracking
    //         // path.pop_back;
    //         visited[newRowIndex][newColIndex] = false;
    //     }
    // }

    // method 1 : // separate code
    // UP 
    // left
    // down
    // right
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> paths;
    vector<vector<bool>> visited(n,vector<bool>(n,false));

    // Important
    if(m[0][0] == 0){
        // No path exist
        return paths;
    }

    // since [0,0] is where rat present => visted[0][0] = true
    visited[0][0] = true;
    solve(m,n,0,0,"",paths,visited);
    return paths;
}

int main(){
    vector<vector<int>> m = {{1,0,0},{1,1,1},{0,1,1}};
    int n = 3;
    vector<string> ans = findPath(m,n);

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
