#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
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

        vector<int> bellmanFord(char src,int n,unordered_map<char,char> &parent){
            vector<int> dValue(n,INT_MAX);

            // initial state
            dValue[src-'A'] = 0;
            parent[src] = '#';

            // main logic
            for(int i=0;i<n-1;i++){
                // perform relaxation with respect to each edge
                for(int j=0;j<n;j++){
                    char nodeVal = 'A' + j;
                    for(auto nbr : adjList[nodeVal]){
                        char nbrNode = nbr.first;
                        int nbrDistance = nbr.second;
                        if(dValue[nodeVal-'A'] != INT_MAX && dValue[nodeVal-'A'] + nbrDistance < dValue[nbrNode-'A']){
                            dValue[nbrNode-'A'] = dValue[nodeVal-'A'] + nbrDistance;
                            parent[nbrNode] = nodeVal;
                        }
                    }
                }
            } 




            // checking -ve wt cycle
            bool negativeCyclePresent = false;
            for(int j=0;j<n;j++){
                char nodeVal = 'A' + j;
                for(auto nbr : adjList[nodeVal]){
                    char nbrNode = nbr.first;
                    int nbrDistance = nbr.second;
                    if(dValue[nodeVal-'A'] != INT_MAX && dValue[nodeVal-'A'] + nbrDistance < dValue[nbrNode-'A']){
                        dValue[nbrNode-'A'] = dValue[nodeVal-'A'] + nbrDistance;
                        negativeCyclePresent = true;
                        break;
                    }
                }
            }

            if(negativeCyclePresent){
                cout << "Negative weight Cycle present " << endl;
            }else{
                cout << " No Negative weight Cycle present " << endl;
            }

            return dValue;
        }
        
};

int main(){
    Graph g;

    g.addEdge('A','B',-1,1);
    g.addEdge('A','C',4,1);
    g.addEdge('B','C',3,1);
    g.addEdge('B','D',2,1);
    g.addEdge('B','E',2,1);
    g.addEdge('D','B',1,1);
    g.addEdge('D','C',5,1);
    g.addEdge('E','D',-3,1);

    // test case for negative wt cycle
    // g.addEdge('A','B',1,1);
    // g.addEdge('B','A',-3,1);

    int n = 5;

    char src = 'A';
    // to get path
    unordered_map<char,char> parent;

    vector<int> shortestDistances = g.bellmanFord(src,n,parent);

    for(int i=0;i<shortestDistances.size();i++){
        char dest = 'A' + i;
        cout << "Shortest Distance from " << src << " to " << dest << " is : " << shortestDistances[i] << endl;

        cout << "Coressponding Shortest Path is : ";
        // printing path
        char temp = dest;
        while(temp != '#'){
            cout << temp << "<-";
            temp = parent[temp];
        }
        cout << endl;
        
    }


    return 0;
}