#include <bits/stdc++.h>
using namespace std;

void DFS_solution(vector<vector<int>> &adjList, int currVertex, int dest, vector<int> &currPath, vector<vector<int>> &allPaths, unordered_set<int> &visited){
    if(currVertex == dest){
        currPath.push_back(currVertex);
        allPaths.push_back(currPath);
        currPath.pop_back();
        return; // !DONT FORGET
    }

    visited.insert(currVertex);

    currPath.push_back(currVertex);

     for(auto neighbourVertex : adjList[currVertex]){
        if(visited.find(neighbourVertex) == visited.end()){
            DFS_solution(adjList, neighbourVertex, dest, currPath, allPaths,visited);
        }
    }
    
    // Backtracking
    currPath.pop_back();

    visited.erase(currVertex);
}


vector<vector<int>> allPaths(vector<vector<int>> &adjList, int src, int dest){
    vector<vector<int>> allPaths;
    vector<int> currPath;
    unordered_set<int> visited;

    DFS_solution(adjList, src, dest, currPath, allPaths, visited);
    return allPaths;
}

int main(){

}