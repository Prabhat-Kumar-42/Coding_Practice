#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Sol
{
    private:
    vector<int> dfs_num, dfs_low, visited, art_pt, parent;
    vector<vector<int>> graph, connected;
    int dfs_count, root, root_children;
    set<pair<int,int>> s, bridge_set;
    vector<pair<int,int>> res; 

    public:
    Sol(int v)
    {
        dfs_num.assign(v, 0);
        art_pt.assign(v, 0);
        dfs_low.assign(v, 0);
        visited.assign(v, 0);
        parent.assign(v, -1);
        graph.assign(v, vector<int>(0));
        connected.assign(v, vector<int>(v, 0));
        dfs_count = 1;
        root_children = 0;
    }
    
    void add_edge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    void articulation_point(int u)
    {
        dfs_low[u] = dfs_num[u] = dfs_count++;
        visited[u] = 1;
        
        for(auto v : graph[u])
        {
            if(!visited[v])
            {
                parent[v] = u;
                if(u == root)
                {
                    root_children++;
                    //cout<<v<<" is children of "<<u<<'\n';
                }
                articulation_point(v);
                
                if(dfs_low[v] > dfs_num[u])
                {
                    bridge_set.insert(make_pair(u, v));
                    //cout<<"at root_children = "<<root_children<<" v = "<<v<<" dfs_num[u] = "<<
                    //dfs_num[u]<<" dfs_low[v] = "<<dfs_low[v]<<" "<< u<<" is art_pt\n";
                    // art_pt[u] = 1;
                }
                dfs_low[u] = min(dfs_low[v], dfs_low[u]);
            }
            else if(v != parent[u])
            {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }
    
    void dfs(int u)
    {
    	visited[u] = 1;
            
        for(int v : graph[u])
    	{
    		if(s.find(make_pair(u, v)) == s.end() && s.find(make_pair(v, u)) == s.end())
    		{
    			s.insert(make_pair(u, v));
    			res.push_back(make_pair(u,v));
    			if(bridge_set.find(make_pair(u, v)) != bridge_set.end() || 
    			    bridge_set.find(make_pair(v, u)) != bridge_set.end())
    			{
    				res.push_back(make_pair(v, u));
    			}
    		}
    		if(!visited[v])
    		{
    			dfs(v);
    		}
    	}
    }
    
    void print(vector<int> &v, int set)
    {
        switch(set)
        {
            case 1 : cout<<"dfs_num\n"; break;
            case 2 : cout<<"dfs_low\n"; break;
            case 3 : cout<<"parent\n"; break;
            case 4 : cout<<"visited\n"; break;
            case 5 : cout<<"art_pt\n"; break;
        }
        
        for(int i = 1; i < v.size(); i++)
        {
            cout<<i<<' ';
        }
        cout<<'\n';
        for(int i = 1; i < v.size(); i++)
        {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
    }
    
    void print_res()
    {
        sort(res.begin(), res.end());
        
        for(auto i : res)
        {
            cout<<( i).first<<' '<< (i).second<<'\n';
        }
    }

    void get_res()
    {
        if(graph.size() < 1)
        {
            return;
        }
        for(int u = 1; u < graph.size(); u++)
        {
            if(!visited[u])
            {
                root = u;
                articulation_point(u);
                if(root_children > 1)
                {
        //            cout<<"root_child = " << root_children<<'\n';
                    art_pt[root] = 1;
                    root_children = 0;
                    root = -1;
                }
                else
                {
                    art_pt[root] = 0;
                }
            }
        }
        
    /*    print(dfs_num, 1);
        print(dfs_low, 2);
        print(parent, 3);
        print(visited, 4);
        print(art_pt, 5);
      */  
        visited.assign(graph.size(), 0);
        
        for(int u = 1; u < graph.size(); u++)
        {
            if(!visited[u])
            {
                dfs(u);
            }
        }
        print_res();
    }
    
    void _delete_()
    {
        graph.clear();
        visited.clear();
        dfs_num.clear();
        dfs_low.clear();
        parent.clear();
        connected.clear();
        art_pt.clear();
        parent.clear();
        dfs_count = 0;
    }
};

int main()
{
    int vertex, edge, count = 1;
    //scanf("%d %d", &a, &b), (a || b)
    while(scanf("%d %d", &vertex, &edge), (vertex || edge))
    {
        cout<<count++<<"\n\n";
        Sol Obj(vertex+1);
        
        int u, v;
        while(edge--)
        {
            cin>>u>>v;
            Obj.add_edge(u, v);
        }
        Obj.get_res();
        Obj._delete_();
        cout<<"#\n";
    }
}


