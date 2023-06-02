#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    
    // Using Union Dinjoint set
//     void make_set(vector<int> &parent, vector<int> &size, int v)
//     {
//         parent[v] = v;
//         size[v] = 1;
//     }
    
//     int find_set(vector<int> &parent, int v)
//     {
//         if(parent[v] == v)
//         {
//             return v;
//         }
//         return parent[v] = find_set(parent, parent[v]);
//     }
    
//     void union_set(vector<int> &parent, vector<int> &size, int a, int b)
//     {
//         a = find_set(parent, a);
//         b = find_set(parent, b);
//         if(a != b)
//         {
//             if(size[a] > size[b])
//             {
//                 swap(a, b);
//             }
//             parent[b] = a;
//             size[a] += size[b];
//         }
//     }
    
//     bool isCycle(int V, vector<int>adj[])
// 	{
// 	    vector<int> parent(V), size(V), visited(V, false);
	    
// 	    for(int i = 0; i < V; i++)
// 	    {
// 	        make_set(parent, size, i);
// 	    }  
	    
// 	    bool res = false;
// 	    for(int i = 0; i < V; i++)
// 	    {
//             int x = find_set(parent, i);
// 	        visited[i] = true;
// 	        for(int v : adj[i])
// 	        {
// 	            if(!visited[v])
// 	            {
//     	            int y = find_set(parent, v);
//     	            if(x == y)
//     	            {
//     	                res = true;
//     	            }
//     	            else
//     	            {
//     	                union_set(parent, size, i, v);
//     	            }
// 	            }
// 	        }
// 	    }
// 	    return res;
// 	}

    bool dfs(vector<int>adj[], vector<bool> &visited, int u, int parent)
    {
        visited[u] =  true;
        
        for(int v : adj[u])
        {
            if(v != parent)
            {
                if(visited[v] || (!visited[v] && dfs(adj, visited, v, u)))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int>adj[])
    {
        vector<bool> visited(V, false);
        bool res = false;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && dfs(adj, visited, i, -1))
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Drive