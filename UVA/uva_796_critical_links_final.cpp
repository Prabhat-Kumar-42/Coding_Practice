#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Critical_Links
{
    private:
    vector<vector<int>> server_links;
    vector<int> dfs_num, dfs_low, visited, parent;
    vector<pair<int, int>> res;
    int dfs_counter;
    
    public:
    Critical_Links(int v)
    {
        server_links.assign(v, vector<int>(0));
        dfs_num.assign(v, 0);
        dfs_low.assign(v, 0);
        visited.assign(v, 0);
        parent.assign(v, -1);
        dfs_counter = 0;
    }
    
    void add_edge(int u, int v)
    {
        server_links[u].push_back(v);
    }
    
    void print_res()
    {
        sort(res.begin(), res.end());   
        cout<<res.size()<<" critical links\n";
        for(auto edge : res)
        {
            cout<<edge.first<<" - "<<edge.second<<'\n';
        }
    }
    
    int get_num(string word)
    {
        int num = 0;
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] < '0' || word[i] > '9')
            {
                continue;
            }
            num = num*10 + (word[i]-'0');
        }
        return num;
    }
    
    void print_list()
    {
        for(int u = 0; u < server_links.size(); u++)
        {
            cout<<u<<" : ";
            for(int v : server_links[u])
            {
                cout<<v<<' ';
            }
            cout<<'\n';
        }
    }
    
    void articulation_bridge(int server)
    {
        visited[server] = 1;
        dfs_low[server] = dfs_num[server] = ++dfs_counter;
        
        for(int connected_server : server_links[server])
        {
            if(!visited[connected_server])
            {
                parent[connected_server] = server; 
                articulation_bridge(connected_server);
                
                if(dfs_low[connected_server] > dfs_num[server])
                {
                    if(server < connected_server)
                    {
                        res.push_back(make_pair(server, connected_server));
                    }
                    else
                    {
                        res.push_back(make_pair(connected_server, server));
                    }
                }
                dfs_low[server] = min (dfs_low[server], dfs_low[connected_server]);
            }
            else if(connected_server != parent[server])
            {
                dfs_low[server] = min (dfs_low[server], dfs_num[connected_server]);
            }
        }
    }
    
    
    void print(vector<int> v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
    }
    
    void get_res()
    {
        for(int u = 0; u < server_links.size(); u++)
        {
            if(!visited[u])
            {
                articulation_bridge(u);
            }
        }
        
        // cout<<"dfs_low : ";
        // print(dfs_low);
        // cout<<"dfs_num : ";
        // print(dfs_num);
        print_res();
    }
    
    void _delete_()
    {
        server_links.clear();
        dfs_num.clear();
        dfs_low.clear();
        visited.clear();
        parent.clear();
        dfs_counter = 0;
        res.clear();
    }
};

int main()
{
    int servers, u, v;

    while(scanf("%d", &servers) == 1)
    {
        Critical_Links obj(servers);
        
        string connected_servers;
        
        for(int i  = 0; i < servers; i++)
        {
            cin>>u;
            cin>>connected_servers;
            
            int cs = obj.get_num(connected_servers);
            while(cs--)
            {
                cin>>v;
                obj.add_edge(u, v);
            }
        }
        
        // obj.print_list();
        obj.get_res();
        obj._delete_();
        cout<<'\n';
    }
}
