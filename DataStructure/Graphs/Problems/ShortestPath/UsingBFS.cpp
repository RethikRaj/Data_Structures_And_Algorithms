#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Graph{
    public:
        unordered_map<char,list<char>> adjList;

        void addEdge(char u,char v,bool direction){
            // direction->0 =>undirected
            // direction->1 =>directed
            if(direction == 0){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }else{
                adjList[u].push_back(v);
            }
        }

        void printAdjList(int n){
            for(int i=0;i<n;i++){
                char nodeVal = 'A' + i;
                cout << nodeVal << " -> " << '{';
                for(auto j : adjList[nodeVal]){
                    cout << j << ", ";
                }
                cout << '}' << endl;
            }
        }

        vector<char> shortestPathBFS(char src,char dest){
            unordered_map<char,bool> visited;
            unordered_map<char,char> parent;
            queue<char> q;

            // initial state
            q.push(src);
            visited[src] = true;
            parent[src] = '#';

            // main logic
            while(!q.empty()){
                char frontNode = q.front();
                q.pop();

                for(char neighbour : adjList[frontNode]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        parent[neighbour] = frontNode;
                        visited[neighbour] = true;
                    }
                }
            }

            // parent map is ready => I can get shortest path between the source and any node

            vector<char> path;

            char temp = dest;
            while(temp != '#'){
                path.push_back(temp);
                temp = parent[temp];
            }

            reverse(path.begin(),path.end());
            return path;
        }

};


int main(){
    Graph g;

    g.addEdge('A','B',0);
    g.addEdge('B','C',0);
    g.addEdge('C','D',0);
    g.addEdge('C','E',0);
    g.addEdge('D','F',0);
    g.addEdge('E','F',0);

    int n = 6;

    g.printAdjList(n);


    char src = 'A';
    char dest = 'F';

    vector<char> shortestPath = g.shortestPathBFS(src,dest);
    // print path;
    for(char node : shortestPath){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}