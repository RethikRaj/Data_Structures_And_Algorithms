#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Graph{
    public:
        unordered_map<char,list<char>> adjList;

        // edge is added between two nodes ( Here Nodes are int type)
        void addEdge(char u,char v,bool direction){
            // direction = 0 -> undirected edge
            // direction = 1 -> directed edge
            if(direction == 0){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }else{
                adjList[u].push_back(v);
            }
        }

        void printAdjList(int n){
            for(int i=0;i<n;i++){
                char vertex = 'A' + i;
                cout << vertex << "-> {";
                list<char> edges = adjList[vertex];
                for(auto j : edges){
                    cout << "(" << j << "),";
                }
                cout << "}" << endl;
            }
        }

        bool cycleDetectionUndirectedBFSHelper(int src,unordered_map<char,bool> &visited){
            queue<char> q;
            unordered_map<char,char> parent;

            // Initial state
            q.push(src);
            visited[src] = true;
            parent[src] = '#'; // # represents an invalid node

            while(!q.empty()){
                char front = q.front();
                q.pop();

                for(char neighbour : adjList[front]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = front;
                    }else{
                        if(parent[front] != neighbour){
                            // cycle present
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        
        bool cycleDetectionUndirectedDFSHelper(int src,unordered_map<char,bool> &visited,char parentOfSource){
            visited[src] = true;
            
            for(char neighbour : adjList[src]){
                if(!visited[neighbour]){
                    bool ans = cycleDetectionUndirectedDFSHelper(neighbour,visited,src);
                    if(ans == true){
                        return true;
                    }
                }
                else{
                    if(parentOfSource != neighbour){
                        return true;
                    }
                }
            }

            return false;
        }

        bool cycleDetectionUndirected(int n){
            // handling disconnected components 

            // Using BFS
            // unordered_map<char,bool> visited;
            // for(int i=0;i<n;i++){
            //     char nodeVal = 'A' + i;
            //     if(!visited[nodeVal]){
            //         bool ans = cycleDetectionUndirectedBFSHelper(nodeVal,visited);
            //         if(ans == true){
            //             return true;
            //         }
            //     }
            // }
            // return false;


            // Using DFS
            unordered_map<char,bool> visited;
            char parent = '#';

            for(int i=0;i<n;i++){
                char nodeVal = 'A' + i;
                if(!visited[nodeVal]){
                    bool ans = cycleDetectionUndirectedDFSHelper(nodeVal,visited,parent);
                    if(ans == true){
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(){
    Graph g;
    g.addEdge('A','B',0);
    g.addEdge('B','E',0);
    g.addEdge('B','G',0);
    g.addEdge('C','F',0);
    g.addEdge('D','E',0);
    g.addEdge('D','G',0);
    g.addEdge('E','C',0);
    
    
    int n = 7;
    g.printAdjList(n);

    if(g.cycleDetectionUndirected(n) == true){
        cout << "CYCLE FOUND" << endl;
    }else{
        cout << "CYCLE NOT FOUND" << endl;
    }


    return 0;
}
