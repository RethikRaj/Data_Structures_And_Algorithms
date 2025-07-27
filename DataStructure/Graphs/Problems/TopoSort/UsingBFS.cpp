#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution{
	public:
	void topoBfs(int n,vector<int> adj[],vector<int> &ans){
	    queue<int> q;
	    unordered_map<int,int> inDegree;
	    
	   // prepare indegree
	   for(int src = 0 ; src < n;src++){
	       for(int nbr : adj[src]){
	           //edge : src -> nbr => inDegree[nbr]++
	           inDegree[nbr]++;
	       }
	   }
	   
	   //initial state => Push nodes with inDegree zero
	   for(int i=0;i<n;i++){
	       if(inDegree[i] == 0){
	           q.push(i);
	       }
	   }
	   
	   //main logic
	   while(!q.empty()){
	       int frontNode = q.front();
	       ans.push_back(frontNode);
	       q.pop();
	       
	       // frontNode is removed from graph => Update its children indegree and if indegree of any children becomes zero push it into queue
	       for(auto nbr : adj[frontNode]){
	           //RemovedEdge : frontNode-> nbr 
	           inDegree[nbr]--;
	           if(inDegree[nbr] == 0){
	               q.push(nbr);
	           }
	       }
	   }
	   
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> ans;
        
        topoBfs(V,adj,ans);
        
        return ans;
	}
};
    