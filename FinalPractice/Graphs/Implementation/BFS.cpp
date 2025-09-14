#include <bits/stdc++.h>
using namespace std;


void BFS_Helper(vector<vector<int>> &adjList, int src,unordered_set<int> &visited, vector<int> &BFS_ans) {
    queue<int> q;
    
    q.push(src);
    visited.insert(src);
    
    while(!q.empty()){
        // a) Pop the front vertex from the queue
        int currVertex = q.front();
        q.pop();
        
        // b) Process the current vertex
        BFS_ans.push_back(currVertex);
        
        // c) Explore all the neighbours of the current vertex
        for(auto neighbourVertex : adjList[currVertex]){
            // d) If neighbour is not visited → push it into the queue and mark it as visited
            if(visited.find(neighbourVertex) == visited.end()){
                q.push(neighbourVertex);
                visited.insert(neighbourVertex);
            }
        }
    }
}

vector<int> BFS(vector<vector<int>> &adjList) {
    int V = adjList.size();
    unordered_set<int> visited;
    vector<int> BFS_ans;
    
    // To Handle unconnected components
    for(int i = 0; i < V; i++){
        if(visited.find(i) == visited.end()){
            BFS_Helper(adjList, i,visited, BFS_ans);
        }
    }
    
    return BFS_ans;
}

    
