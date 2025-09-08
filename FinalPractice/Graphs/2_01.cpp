#include <bits/stdc++.h>
using namespace std;


// Method 1 : BFS
class SolutionBFS {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int neighbour : rooms[curr]){
                if(visited.find(neighbour) == visited.end()){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};

// Method 2 : Same logic using DFS
class SolutionDFS {
public:
    void dfs(vector<vector<int>>& rooms, int curr,unordered_set<int> &visited){
        visited.insert(curr);

        for(int neighbour : rooms[curr]){
            if(visited.find(neighbour) == visited.end()){
                dfs(rooms ,neighbour, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, 0, visited);

        return visited.size() == rooms.size();
    }
};