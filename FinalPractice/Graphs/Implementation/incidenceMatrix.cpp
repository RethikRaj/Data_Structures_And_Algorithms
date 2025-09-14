#include <iostream>
#include <vector>
using namespace std;

class UnweightedGraph{
    private:
        int V;
        int E;
        int edgeCount;
        vector<vector<int>> incidenceMatrix;

    public:
        UnweightedGraph(int V, int E){
            this->V = V;
            this->E = E;
            this->edgeCount = 0;
            incidenceMatrix.resize(V, vector<int>(E, 0));
        }

        void addEdge(int u, int v, bool undirected = true){
            if(this->edgeCount >= this->E){
                cout << "All Edges already added" << endl; 
                return;
            }

            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            if(undirected){
                if(u == v){
                    incidenceMatrix[u][edgeCount] = 2;
                }else{
                    incidenceMatrix[u][edgeCount] = 1;
                    incidenceMatrix[v][edgeCount] = 1;
                }
            }
            else{
                if(u == v){
                    incidenceMatrix[u][edgeCount] = 0;
                }else{
                    incidenceMatrix[u][edgeCount] = -1;
                    incidenceMatrix[v][edgeCount] = 1;
                }
                
            }
            edgeCount++;
        }

        void displayGraph(){
            cout << "Incidence Matrix:" << endl;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < E; j++) {
                    cout << incidenceMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

class WeightedGraph{
    private:
        int V;
        int E;
        int edgeCount;
        vector<vector<int>> incidenceMatrix;

    public:
        WeightedGraph(int V, int E){
            this->V = V;
            this->E = E;
            this->edgeCount = 0;
            incidenceMatrix.resize(V, vector<int>(E, 0));
        }

        void addEdge(int u, int v, int wt,bool undirected = true){
            if(this->edgeCount >= this->E){
                cout << "All Edges already added" << endl; 
                return;
            }

            if (u >= V || v >= V || u < 0 || v < 0) {
                cout << "Invalid vertex index!" << endl;
                return;
            }

            if(undirected){
                if(u == v){
                    incidenceMatrix[u][edgeCount] = 2*wt;
                }else{
                    incidenceMatrix[u][edgeCount] = wt;
                    incidenceMatrix[v][edgeCount] = wt;
                }
            }
            else{
                if(u == v){
                    incidenceMatrix[u][edgeCount] = 0;
                }else{
                    incidenceMatrix[u][edgeCount] = -wt;
                    incidenceMatrix[v][edgeCount] = wt;
                }
                
            }
            edgeCount++;
        }

        void displayGraph(){
            cout << "Incidence Matrix:" << endl;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < E; j++) {
                    cout << incidenceMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    UnweightedGraph ug(4, 6);
    ug.addEdge(0, 1);
    ug.addEdge(0, 3);
    ug.addEdge(1, 2);
    ug.addEdge(2, 3);
    ug.addEdge(1, 3);
    ug.addEdge(1, 1);
    ug.displayGraph();

    WeightedGraph wg(4, 6);
    wg.addEdge(0, 1, 1);
    wg.addEdge(0, 3, 2);
    wg.addEdge(1, 2, 3);
    wg.addEdge(2, 3, 4);
    wg.addEdge(1, 3, 5);
    wg.addEdge(1, 1, 6);
    wg.displayGraph();

    return 0;
}