#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;     

class compare{
    public:
        bool operator()(pair<char,int> a,pair<char,int> b) const{
            return a.second < b.second;
        }
};

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

        vector<int> dijkstra(char src,int n,unordered_map<char,char> &parent){
            set<pair<char,int>, compare> st;
            vector<int> dValue(n,INT_MAX);
            set<char> selectedVertices;

            // initial state
            dValue[src-'A'] = 0;
            st.insert({src,0});
            parent[src] = '#';

            // main logic
            while(!st.empty()){
                pair<char,int> topEle = *(st.begin());
                char topNode = topEle.first;
                selectedVertices.insert(topNode);

                // pop this node
                st.erase(st.begin());

                for(auto nbr : adjList[topNode]){
                    char nbrNode = nbr.first;
                    int nbrDistance = nbr.second;
                    if(selectedVertices.find(nbrNode) == selectedVertices.end() && dValue[topNode-'A'] + nbrDistance < dValue[nbrNode-'A']){
                        // update set -> First need to find old entry then delete it , then insert new entry
                        auto it = st.find({nbrNode,dValue[nbrNode-'A']});
                        if(it != st.end()){
                            // entry found -> remove it
                            st.erase(it);
                        }
                        
                        // update dValue
                        dValue[nbrNode-'A'] = dValue[topNode-'A'] + nbrDistance;

                        // insert new entry into set
                        st.insert({nbrNode,dValue[nbrNode-'A']});

                        // update parent
                        parent[nbrNode] = topNode;
                    }
                }
            }

            return dValue;
        }
        
};

int main(){
    Graph g;

    g.addEdge('A','D',6,0);
    g.addEdge('A','F',9,0);
    g.addEdge('B','E',9,0);
    g.addEdge('B','F',14,0);
    g.addEdge('B','C',7,0);
    g.addEdge('C','D',15,0);
    g.addEdge('C','E',10,0);
    g.addEdge('D','E',11,0);
    g.addEdge('E','F',2,0);

    int n = 6;

    char src = 'A';
    // to get path
    unordered_map<char,char> parent;

    vector<int> shortestDistances = g.dijkstra(src,n,parent);

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