#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

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

        void topoSortDFS(char src,unordered_map<char,bool> &visited,stack<char> &s){
            visited[src] = true;
        
            for(auto nbr : adjList[src]){
                if(!visited[nbr.first]){
                    topoSortDFS(nbr.first,visited,s);
                }
            }

            s.push(src);
        }

        vector<int> shortestPathDFS(char src,unordered_map<char,char> &parent){
            stack<char> topoOrder;
            unordered_map<char,bool> visited;
            // get topological sort
            topoSortDFS(src,visited,topoOrder);

            int n = topoOrder.size();
            vector<int> dValue(n,INT_MAX);
            // initial state
            int src_index = src-'A';
            dValue[src_index] = 0;
            parent[src] = '#';

            // main logic
            while(!topoOrder.empty()){
                char top = topoOrder.top();
                topoOrder.pop();

                for(auto nbr : adjList[top]){
                    int top_index = top - 'A';
                    int nbr_index = nbr.first - 'A';

                    if(dValue[top_index] + nbr.second < dValue[nbr_index]){
                        dValue[nbr_index] = dValue[top_index] + nbr.second;
                        parent[nbr.first] = top;
                    }
                }
            }

            return dValue;
        }
        
};

int main(){
    Graph g;

    g.addEdge('A','B',5,1);
    g.addEdge('A','C',13,1);
    g.addEdge('A','E',3,1);
    g.addEdge('B','C',7,1);
    g.addEdge('B','E',1,1);
    g.addEdge('D','C',2,1);
    g.addEdge('E','D',6,1);

    int n = 5;

    char src = 'A';
    // to get paths also we can use parent concept
    unordered_map<char,char> parent;
    vector<int> shortestDistances = g.shortestPathDFS(src,parent);

    
    for(int i=0;i<shortestDistances.size();i++){
        char dest = 'A' + i;
        cout << "Shortest Distance from " << src << " to " << dest << " is : " << shortestDistances[i] << endl;
        // printing path
        cout << "Corresponding Shortest Path is : ";
        stack<char> path;
        char temp = dest;
        while(temp != '#'){
            path.push(temp);
            temp = parent[temp];
        }

        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }

    


    return 0;
}