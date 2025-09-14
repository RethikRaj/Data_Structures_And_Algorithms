#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& adjList, int src, vector<int> &distance, unordered_set<int> &visited){
    queue<int> q;
    
    q.push(src);
    visited.insert(src);
    distance[src] = 0;
    
    while(!q.empty()){
        int currVertex = q.front();
        q.pop();
        
        for(auto neighbourVertex : adjList[currVertex]){
            if(visited.find(neighbourVertex) == visited.end()){
                q.push(neighbourVertex);
                visited.insert(neighbourVertex);
                // !Parent of neighbourVertex is currVertex
                distance[neighbourVertex] = distance[currVertex] + 1;
            }
        }
    }
}

vector<int> shortestPath(vector<vector<int>>& adjList, int src) {
    int V = adjList.size();
    vector<int> distance(V, -1); // distan
    unordered_set<int> visited;
    
    BFS(adjList, src, distance, visited);
    return distance;
}