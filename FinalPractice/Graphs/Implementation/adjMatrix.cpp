#include <iostream>
#include <vector>
using namespace std;


class UnweightedGraph{
    private:
        int V;
        vector<vector<int>> adjMatrix;   

    public:
        UnweightedGraph(int V){
            this->V = V;
            adjMatrix.resize(V, vector<int>(V, 0));
        }     

        void addEdge(int u, int v, bool undirected = true){
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            adjMatrix[u][v] = 1;
            if(undirected){
                adjMatrix[v][u] = 1;
            }
        }

        void displayGraph(){
            for(int i=0;i<V;i++){
                cout << i << " -> ";
                for(int j=0;j<V;j++){
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

class WeightedGraph{
    private:
        int V;
        vector<vector<int>> adjMatrix;   

    public:
        WeightedGraph(int V){
            this->V = V;
            adjMatrix.resize(V, vector<int>(V, 0));
        }     

        void addEdge(int u, int v, int wt, bool undirected = true){
            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            adjMatrix[u][v] = wt;
            if(undirected){
                adjMatrix[v][u] = wt;
            }
        }

        void displayGraph(){
            for(int i=0;i<V;i++){
                cout << i << " -> ";
                for(int j=0;j<V;j++){
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    UnweightedGraph ug(7);
    ug.addEdge(0, 1);
    ug.addEdge(0, 2);
    ug.addEdge(1, 5);
    ug.addEdge(2, 5);
    ug.addEdge(2, 3);
    ug.addEdge(3, 6);
    ug.addEdge(4, 6);
    ug.displayGraph();

    cout << "------------------------------" << endl;

    WeightedGraph wg(7);
    wg.addEdge(0, 1, 1, false);
    wg.addEdge(0, 2, 2, false);
    wg.addEdge(1, 5, 3, false);
    wg.addEdge(2, 5, 4, false);
    wg.addEdge(2, 3, 5, false);
    wg.addEdge(3, 6, 6, false);
    wg.addEdge(4, 6, 7, false);
    wg.displayGraph();
}