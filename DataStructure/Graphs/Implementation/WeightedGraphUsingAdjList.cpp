#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Graph{
    public:
        unordered_map<int,list<pair<int,int>>> adjList;

        // edge is added between two nodes ( Here Nodes are int type)
        void addEdge(int u,int v,int weight,bool direction){
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
                cout << i << "-> {";
                list<pair<int,int>> edges = adjList[i];
                for(auto j : edges){
                    cout << "(" << j.first << "," << j.second << "),";
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
    g.addEdge(0,1,3,1);
    g.addEdge(0,2,5,1);
    g.addEdge(1,2,10,1);
    g.addEdge(2,3,20,1);
    int n = 4;
    g.printAdjList(n);

    return 0;
}