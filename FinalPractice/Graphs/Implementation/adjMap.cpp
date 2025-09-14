#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//  Note : I have used vector<unordered_set<int>> and vector<unordered_map <int, int> > for unweighted and weighted graphs respectively. If the graph has vertices labelled as characters or even integers(but not in range of 0 to n-1), then use                      unordered_map<char, unordered_set<char>> and unordered_map<char, unordered_map <char, int> > for unweighted and weighted graphs respectively.

class UnweightedGraph{
    private:
        int V;
        vector<unordered_set<int>> adjMap;

    public:
        UnweightedGraph(int V){
            this->V = V;
            adjMap.resize(V);
        }

        void addEdge(int u, int v, bool undirected = true){
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            adjMap[u].insert(v);
            if(undirected){
                adjMap[v].insert(u);
            }
        }

        void displayGraph(){
            for(int i=0;i<V;i++){
                cout << i << " -> ";
                for(auto node : adjMap[i]){
                    cout << node << " ";
                }
                cout << endl;
            }
        }
};

class WeightedGraph{
    private:
        int V;
        vector<unordered_map<int, int>> adjMap;

    public:
        WeightedGraph(int V){
            this->V = V;
            adjMap.resize(V);
        }

        void addEdge(int u, int v,int wt,bool undirected = true){
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            adjMap[u][v] = wt;
            if(undirected){
                adjMap[v][u] = wt;
            }
        }

        void displayGraph(){
            for(int i=0;i<V;i++){
                cout << i << " -> ";
                for(auto node : adjMap[i]){
                    cout << "(" << node.first << ", " << node.second << ") ";
                }
                cout << endl;
            }
        }
};

int main(){
    // UnweightedGraph g(7);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 5);
    // g.addEdge(2, 5);
    // g.addEdge(2, 3);
    // g.addEdge(3, 6);
    // g.addEdge(4, 6);
    // g.displayGraph();

    WeightedGraph g(7);
    g.addEdge(0, 1, 1, false);
    g.addEdge(0, 2, 2, false);
    g.addEdge(1, 5, 3, false);
    g.addEdge(2, 5, 4, false);
    g.addEdge(2, 3, 5, false);
    g.addEdge(3, 6, 6, false);
    g.addEdge(4, 6, 7, false);
    g.displayGraph();
}