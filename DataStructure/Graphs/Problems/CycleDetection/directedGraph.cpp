#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <unordered_set>

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

        bool cycleDetectionDirectedDFSHelper(int src,unordered_map<char,bool> &visited,unordered_set<char> &currPath){
            visited[src] = true;
            currPath.insert(src);

            for(char neighbour : adjList[src]){
                if(!visited[neighbour]){
                    bool ans = cycleDetectionDirectedDFSHelper(neighbour,visited,currPath);
                    if(ans == true){
                        return true;
                    }
                }
                else{// already visited
                    if(currPath.find(neighbour) != currPath.end()){
                        return true;
                    }
                }
            }
            currPath.erase(src);
            return false;
        }

        void cycleDetectionDirectedBFSHelper(int n,vector<char> &topoSortAns){
            queue<char> q;
            unordered_map<char,int> inDegree;
            
            // prepare indegree
            for(int i = 0 ; i < n;i++){
                char src = 'A' + i;
                for(char nbr : adjList[src]){
                    //edge : src -> nbr => inDegree[nbr]++
                    inDegree[nbr]++;
                }
            }
            
            //initial state => Push nodes with inDegree zero
            for(int i=0;i<n;i++){
                char nodeVal = 'A' + i;
                if(inDegree[nodeVal] == 0){
                    q.push(nodeVal);
                }
            }
            
            //main logic
            while(!q.empty()){
                char frontNode = q.front();
                topoSortAns.push_back(frontNode);
                q.pop();
                
                // frontNode is removed from    graph => Update its children indegree and if indegree of any children becomes zero push it into queue
                for(auto nbr : adjList[frontNode]){
                    //RemovedEdge : frontNode-> nbr 
                    inDegree[nbr]--;
                    if(inDegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }

        bool cycleDetectionDirected(int n){
            // handling disconnected components 

            // Using DFS
            // unordered_map<char,bool> visited;
            // unordered_set<char> currPath;

            // for(int i=0;i<n;i++){
            //     char nodeVal = 'A' + i;
            //     if(!visited[nodeVal]){
            //         bool ans = cycleDetectionDirectedDFSHelper(nodeVal,visited,currPath);
            //         if(ans == true){
            //             return true;
            //         }
            //     }
            // }
            // return false;


            // Using BFS
            vector<char> topoSortAns;
            cycleDetectionDirectedBFSHelper(n,topoSortAns);
            if(topoSortAns.size() == n){
                return false;
            }else{
                return true;
            }
        }

};



int main(){
    Graph g;
    g.addEdge('A','B',1);
    g.addEdge('A','C',1);
    g.addEdge('C','D',1);
    g.addEdge('D','E',1);
    g.addEdge('E','B',1);
    // g.addEdge('E','C',1);
    
    int n = 5;
    g.printAdjList(n);

    if(g.cycleDetectionDirected(n) == true){
        cout << "CYCLE FOUND" << endl;
    }else{
        cout << "CYCLE NOT FOUND" << endl;
    }


    return 0;
}