#include <iostream>
using namespace std;
#include<vector>
#include<cstring>

int dfs(vector<int> adj[], bool visited[], int u)
{
    int res = 0;
    for(int v: adj[u])
    {
        if(!visited[v])
        {
            res++;
            visited[v] = true;
            res += dfs(adj, visited, v);
        }
    }
    return res;
}

int main()
{
    while(1)
    {
        int V;
        cin>>V;
        
        // cout<<V<<'\n';
        
        if(!V)
        {
            break;
        }
        
        vector<int> adj[V+1];
        bool visited[V+1] = {false};
        
        int u, v;
        cin>>u;
        
        // cout<<u<<' ';
        
        int curr = u;
        
        while(curr)
        {
            cin>>v;
            if(!v)
            {
                cin>>u;
                // cout<<'\n'<<u<<' ';
                curr = u;
            }
            else
            {
                // cout<<v<<' ';
                adj[curr].push_back(v);
            }
        }
        // cout<<'\n';
        int t;
        cin>>t;
        // cout<<t<<' ';
        while(t--)
        {
            memset(visited, false, sizeof(visited));
            int x;
            cin>>x;
            
            // cout<<x<<'\n';
            
            int access = dfs(adj, visited, x);
            int count = V - access; 
            cout<<count;
            for(int i = 1; i < V+1; i++)
            {
                count--;
                if(!visited[i])
                {
                    cout<<' '<<i;
                    
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}