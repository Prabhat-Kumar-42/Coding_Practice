#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &ances, int u)
	{
	    visited[u] = true;
	    ances[u] = true;
	    for(int v: adj[u])
	    {
	        if(!visited[v] && dfs(adj, visited, ances, v))
	        {
	            return true;
	        }
	        else if(ances[v])
	        {
	            return true;
	        }
	    }
	    ances[u] = false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);
	    vector<bool> ances(V, false);
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i] && dfs(adj, visited, ances, i))
	        {
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends