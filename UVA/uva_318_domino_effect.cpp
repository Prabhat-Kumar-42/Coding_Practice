#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int dist[505];
vector<pair<int, int>> adj[505];
int a, b, n, m, t, c;
double res;

void Dijkstra()
{
    for(int i = 1; i <=n; i++)
    {
        dist[i] = INT_MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        int u = front.second;
        int d = front.first;
        if(d > dist[u])
        {
            continue;
        }
        for(auto e: adj[u])
        {
            int w = e.second;
            int v = e.first;
            
            if(d+w < dist[v])
            {
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }
}

void getLastDomino()
{
    a = 1;
    b = -1;
    res = 0.0;
    
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] != INT_MAX && dist[i] > res)
        {
            res = dist[i];
            a = i;
        }
    }
    
    for(int u = 1; u <= n; u++)
    {
        cout<<"u = "<<u<<'\n';
        for(auto e: adj[u])
        {
            int v = e.first;
            int d = e.second;
            
            cout<<"v = "<<v<<" d = "<<d<<'\n';
            int x = dist[u];
            if(x == INT_MAX)
            {
                continue;
            }
            
            int y = dist[v];
            if(y == INT_MAX)
            {
                continue;
            }
            
            cout<<"x = "<<x<<" y = "<<y<<'\n';
            if(x < y)
            {
                swap(x,y);
                cout<<"swapped : x = "<<x<<" y = "<<y<<'\n';
            }
            
            double last = x + (d - (x-y))/2.0;
            cout<<"res = "<<res<<'\n';
            if(last > res)
            {
                res = last;
                a = min(u, v);
                b = max(u, v);
            }
            cout<<"last = "<<last<<" res = "<< res<<" a = "<<a<<" b = "<<b<<'\n';
        }
        cout<<'\n';
    }
    
    cout<<'\n';
}

int main()
{
    cout.precision(1);
    cout<<fixed;
    
    while(cin>>n>>m && (n || m))
    {
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        
        while(m--)
        {
            cin>>a>>b>>c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        
        Dijkstra();
        getLastDomino();
        cout << "System #" << ++t << endl;
		cout << "The last domino falls after " << res << " seconds,";
		if( b == -1 ) cout << " at key domino " << a << ".\n";
		else cout << " between key dominoes " << a << " and " << b << ".\n";
		cout << endl;
    }
    return 0;
}