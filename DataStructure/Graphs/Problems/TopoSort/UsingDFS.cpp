#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution{
	public:
	void topoDfs(vector<int> adj[],int src,unordered_map<int,bool> &visited,vector<int> &ans){
	    visited[src] = true;
	    
	    for(int nbr : adj[src]){
	        if(!visited[nbr]){
	            topoDfs(adj,nbr,visited,ans);
	        }
	    }
	    
	    ans.push_back(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    unordered_map<int,bool> visited;
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            topoDfs(adj,i,visited,ans);
	        }
	    }
	    
	    reverse(ans.begin(),ans.end());
	    return ans;
	    
	}
};

