#include <bits/stdc++.h>
using namespace std;

void DFS_Helper(vector<vector<int>>& adjList, int src, unordered_set<int> &visited, vector<int> &DFS_ans){
    // 1. mark curr vertex as visited
    visited.insert(src);
    // 2. Process curr vertex
    DFS_ans.push_back(src);
    // 3. Visit the unvisited neighbours
    for(auto neighbourVertex : adjList[src]){
        if(visited.find(neighbourVertex) == visited.end()){
            DFS_Helper(adjList, neighbourVertex, visited, DFS_ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adjList) {
    int V = adjList.size();
    unordered_set<int> visited;
    vector<int> DFS_ans;
    
    // To Handle unconnected components
    for(int i = 0; i < V; i++){
        if(visited.find(i) == visited.end()){
            DFS_Helper(adjList, i,visited, DFS_ans);
        }
    }
    
    return DFS_ans;
}