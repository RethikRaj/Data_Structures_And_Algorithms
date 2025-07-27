#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adjList;

        // edge is added between two nodes ( Here Nodes are int type)
        void addEdge(int u,int v,bool direction){
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
                cout << i << "-> {";
                list<int> edges = adjList[i];
                for(auto j : edges){
                    cout << j << ", ";
                }
                cout << "}" << endl;
            }

            // Problem : empty list not printing
            // for(auto i : adjList){
            //     cout << i.first << " -> {";
            //     for(auto j : i.second){
            //         cout << j << ", ";
            //     }
            //     cout << "}" << endl;
            // }
        }


};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    int n = 4;
    g.printAdjList(n);

    return 0;
}
