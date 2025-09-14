#include <iostream>
#include <vector>
using namespace std;

class Edge{
    public:
        int src, dest, weight;
    
    public:
        Edge(int src, int dest, int weight){
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }
};

class EdgeList{
    private:
        int V;
        vector<Edge*> edges;
    
    public:
        EdgeList(int V){
            this->V = V;
        }

        void addEdge(int u, int v, int wt=1, bool undirected = true){
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            // Add edge
            edges.push_back(new Edge(u, v, wt));
            if(undirected){
                edges.push_back(new Edge(v, u, wt));
            }
        }

        void displayGraph(){
            for(int i=0;i < edges.size();i++){
                Edge* edge = edges[i];
                cout << "(" << edge->src << " -> " << edge->dest << " : " << edge->weight  << ")" << endl;
            }
        }
};

int main(){
    EdgeList g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.displayGraph();
}