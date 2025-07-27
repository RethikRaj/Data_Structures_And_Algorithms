#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;     



class Graph{
    public:
        unordered_map<char,list<pair<char,int>>> adjList;

        void addEdge(char u,char v,int weight,bool direction){
            // direction->0 =>undirected
            // direction->1 =>directed
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

        // void floydWarshall(char helper){
        //     // base case
        // recursiive way pendning
        //     // one case me solve remaining recursion will handle

        // }

        vector<vector<int>> floydWarshallAlgo(int n){
            vector<vector<int>> dist(n,vector<int>(n,1e9));

            // initial state : 2 Steps
            // step 1 : shortest distance from node to itself is 0
            for(int i=0;i<n;i++){
                dist[i][i] = 0;
            }
            // step 2 : update the edge value
            for(auto a : adjList){
                for(auto b : a.second){
                    dist[a.first-'A'][b.first-'A'] = b.second;
                }
            }

            // main logic
            for(int helper = 0;helper < n;helper++){
                for(int src = 0;src < n;src++){
                    for(int dest = 0;dest < n;dest++){
                        dist[src][dest] = min(dist[src][dest] , dist[src][helper] + dist[helper][dest]);
                    }
                }
            }

            return dist;
        }
        
};

int main(){
    Graph g;

    g.addEdge('A','C',-2,1);
    g.addEdge('B','A',4,1);
    g.addEdge('B','C',3,1);
    g.addEdge('C','D',2,1);
    g.addEdge('D','B',-1,1);
    

    int n = 4;

    vector<vector<int>> allPairShortestDistances = g.floydWarshallAlgo(n);



    for(int i=0;i<n;i++){
        char src = 'A' + i;
        for(int j=0;j<n;j++){
            char dest = 'A' + j;
            cout << "Shortest Distance from " << src << " to " << dest << " is : " << allPairShortestDistances[i][j] << endl;
        }
    }

    


    return 0;
}