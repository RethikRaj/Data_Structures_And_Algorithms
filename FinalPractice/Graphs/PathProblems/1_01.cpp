#include <bits/stdc++.h>
using namespace std;

bool DFS_solution(vector<vector<int>> &adjList, int currVertex, int dest, unordered_set<int> &visited){
    if(currVertex == dest){
        return true;
    }

    visited.insert(currVertex);

    for(auto neighbourVertex : adjList[currVertex]){
        if(visited.find(neighbourVertex) == visited.end()){
            bool ans = DFS_solution(adjList, neighbourVertex, dest, visited);
            if(ans){
                return true;
            }
        }
    }

    return false;
}

bool BFS_solution(vector<vector<int>> &adjList, int src, int dest, unordered_set<int> &visited){
    queue<int> q;

    q.push(src);
    visited.insert(src);

    while(!q.empty()){
        int currVertex = q.front();
        q.pop();

        if(currVertex == dest){
            return true;
        }

        for(auto neighbourVertex : adjList[currVertex]){
            if(visited.find(neighbourVertex) == visited.end()){
                q.push(neighbourVertex);
                visited.insert(neighbourVertex);
            }
        }

    }

    return false;
}

bool isPathExists(vector<vector<int>> &adjList, int src, int dest){
    unordered_set<int> visited;
    // return DFS_solution(adjList, src, dest, visited);

    return BFS_solution(adjList, src, dest, visited);
}