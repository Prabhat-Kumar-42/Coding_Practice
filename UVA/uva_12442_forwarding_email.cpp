#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define NOT_RECORDED 0

int dfs(vector<bool> &visited, vector<int> adj[], vector<int> &res, int u)
{
    int length = res[u] = 1;
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            length += dfs(visited, adj, res, v);
            if(length > res[u])
            {
                res[u] = length;
            }
            length = 1;
        }
    }
    visited[u] = false;
    return res[u];
}

int main()
{
    int test_case;
    cin>>test_case;
    
    for(int i = 1; i <= test_case; i++)
    {
        int size;
        cin>>size;
        
        vector<int> adj[size+1], length(size+1, 0);
        vector<bool> visited(size+1, false);
        
        for(int j = 0; j < size; j++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        int res = 0, res_length = 0;
        for(int u = 1; u < size+1; u++)
        {
            if(length[u] == NOT_RECORDED)
            {
                dfs(visited, adj, length, u);
            }
            if(length[u] > res_length)
            {
                res_length = length[u];
                res = u;
            }
        }
        
        cout<<"Case "<<i<<": "<<res<<'\n';
    }
    return 0;
}
        