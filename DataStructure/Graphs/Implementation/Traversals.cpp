#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Graph{
    public:
        unordered_map<char,list<pair<char,int>>> adjList;

        // edge is added between two nodes ( Here Nodes are int type)
        void addEdge(char u,char v,int weight,bool direction){
            // direction = 0 -> undirected edge
            // direction = 1 -> directed edge
            if(direction == 0){
                adjList[u].push_back({v,weight});
                adjList[v].push_back({u,weight});
            }else{
                adjList[u].push_back({v,weight});
            }
        }

        void printAdjList(int n){
            for(int i=0;i<n;i++){
                char vertex = 'A' + i;
                cout << vertex << "-> {";
                list<pair<char,int>> edges = adjList[vertex];
                for(auto j : edges){
                    cout << "(" << j.first << "," << j.second << "),";
                }
                cout << "}" << endl;
            }
        }

        void BFShelper(char src,unordered_map<char,bool> &visited){
            queue<char> q;

            // initial state
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                char curr = q.front();
                q.pop();
                cout << curr << ", ";
                // add the current vertex's unvisited adjacent vertices to the queue
                list<pair<char,int>> adjacentVertices = adjList[curr];
                for(auto i : adjacentVertices){
                    if(visited[i.first] == false){
                        q.push(i.first);
                        visited[i.first] = true;
                    }                        
                }
            }
        }

        void BFStraversal(int n){
            unordered_map<char,bool> visited;

            for(int i=0;i<n;i++){
                char src = 'A' + i;
                if(!visited[src]){
                    BFShelper(src,visited);
                }
            }

            cout << endl;
        }
        
        void DFShelper(char src,unordered_map<char,bool> &visited){
            cout << src << ", ";
            visited[src] = true;
            for(auto i : adjList[src]){
                if(!visited[i.first]){
                    DFShelper(i.first,visited);
                }
            }


            // // base case
            // if(visited[src] == true){
            //     return;
            // }

            // // 1 case me solve remaining recursion 
            // cout << src << ", ";
            // visited[src] = true;
            // for(auto i : adjList[src]){
            //     DFShelper(i.first,visited);
            // }
        }

        void DFStraversal(int n){
            unordered_map<char,bool> visited;
            
            // to handle disconnected components
            
            for(int i=0; i < n;i++){
                char src = 'A'+i;
                if(!visited[src]){
                    DFShelper(src,visited);
                }
            }
            
        }
};



int main(){
    Graph g;
    g.addEdge('A','B',3,1);
    g.addEdge('A','F',3,1);
    g.addEdge('B','C',3,1);
    g.addEdge('B','E',3,1);
    g.addEdge('C','D',3,1);
    g.addEdge('D','G',3,1);
    g.addEdge('E','D',3,1);
    g.addEdge('F','E',3,1);
    g.addEdge('H','I',3,1);
    g.addEdge('I','J',3,1);
    
    int n = 10;
    g.printAdjList(n);

    cout << "BFS : ";
    g.BFStraversal(n);

    cout << "DFS : ";
    g.DFStraversal(n);
    cout << endl;

    return 0;
}

