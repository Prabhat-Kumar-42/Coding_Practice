#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<int> adj[], vector<int> &weight, int u, 
        int &res_weight, int &res_path)
{
    res_path = u;
    if(adj[u].empty())
    {
        return;
    }
    int current_max = 0;
    for(int v : adj[u])
    {
        if(weight[v] > weight[current_max])
        {
            current_max = v;
        }
    }
    res_weight += weight[current_max];
    dfs(adj, weight, current_max, res_weight, res_path);
}

int main()
{
    int test_case;
    cin>>test_case;
    
    for(int i = 1; i <= test_case; i++)
    {
        int nodes, edges;
        cin>>nodes>>edges;
        
        vector<int> adj[nodes];
        vector<int> weight(nodes, 0);
        
        for(int u = 0; u < nodes; u++)
        {
            cin>>weight[u];
        }
        
        for(int j = 0; j < edges; j++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        int res_weight = 0, res_path = 0;
        
        dfs(adj, weight, 0, res_weight, res_path);
        
        cout<<"Case "<<i<<": "<<res_weight<<' '<<res_path<<'\n';
    }
    return 0;
}
