//UVA 10765 Question Solution

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Doves_and_Bombs
{
    private:
    vector<vector<int>> stations;
    vector<int> dfs_num, dfs_low, visited, parent, is_art_pt;
    int dfs_counter, root, root_children, no_of_stations_to_delete;
     vector<pair<int,int>> result;
    int vertex;
    
    public:
    
    Doves_and_Bombs(int v, int no_of_stations_to_delete)
    {
        stations.assign(v, vector<int>(0));
        dfs_num.assign(v, 0);
        dfs_low.assign(v, 0);
        visited.assign(v, 0);
        parent.assign(v, -1);
        is_art_pt.assign(v, 0);
        dfs_counter = 0;
        root = -1;
        root_children = 0;
        vertex = v;
        this->no_of_stations_to_delete = no_of_stations_to_delete;
    }
    
    void addEdge(int u, int v)
    {
        if(u > stations.size() || v > stations.size())
        {
            return;
        }
        stations[u].push_back(v);
        stations[v].push_back(u);
    }
    
    void createGraph()
    {
        int u, v;
        cin>>u>>v;
        
        while((u != -1)&&(v != -1))
        {
            if(u >= vertex || v >= vertex)
            {
                cin>>u>>v;
            }
            if(u != -1 && v != -1)
            {
                addEdge(u,v);
            }
            cin>>u>>v;
        }
    }
    
    void articulationPoints(int u)
    {
        dfs_num[u] = dfs_low[u] = ++dfs_counter;
        visited[u] = 1;
        
        for(int v : stations[u])
        {
            if(!visited[v])
            {
                if(u == root)
                {
                    root_children++;
                }
                
                parent[v] = u;
                articulationPoints(v);
                
                if(dfs_low[v] >= dfs_num[u])
                {
                    is_art_pt[u]++;
                }
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
            else if(/*parent[u] != -1 &&*/ v != parent[u])
            {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }
    
    void print_res(vector<pair<int,int>> &articulation_points)
    {
        if(articulation_points.size() < 1)
        {
            return;
        }
        
        auto i = articulation_points.end()-1;

        // if(i == articulation_points.begin())
        // {
        //     cout<<i->second<<' '<<i->first<<'\n';
        //     return;
        // }
        
        vector<pair<int, int>> res;
        
        auto j = i;
        while((i != articulation_points.begin()-1))
        {   
            while( i->first == j->first)
            {
                // cout<<"at i "<<i->first<<' '<<i->second<<" pushed "<<j->second<<' '<<j->first<<" in res\n";
                res.push_back(make_pair(j->second, j->first));
                j--;
            }
            sort(res.begin(), res.end());
            result.insert(result.end(), res.begin(), res.end());
            res.clear();
            i = j;
        }
        
        for(auto i = result.begin(); i != result.end(); i++)
        {
            if(no_of_stations_to_delete--)
            {
                cout<<i->first<<' '<<i->second<<'\n';
            }
            else
            {
                break;
            }
        }
    }
    
    void get_res()
    {
        for(int v = 0; v < stations.size(); v++)
        {
            if(!visited[v])
            {
                root = v;
                articulationPoints(v);
                if(root_children > 1)
                {
                    is_art_pt[v] = root_children;
                }
                root_children = 0;
            }
        }
        
        vector<pair<int,int>> res;
        
        for(int v = 0; v < vertex; v++)
        {
            if(is_art_pt[v] == 0)
            {
                res.push_back(make_pair(1, v));
            }
            else
            {
                if(parent[v] != -1 /*&& (dfs_low[v] != dfs_num[parent[v]])*/)
                {
                    is_art_pt[v]++;
                }
                res.push_back(make_pair(is_art_pt[v], v));
            }
        }
        
        print_list(dfs_low, 1);
        print_list(dfs_num, 2);
        print_list(parent, 3);
        print_list(visited, 4);
        print_list(is_art_pt, 5);
        sort(res.begin(), res.end());
        
        print_res(res);
    }
    
    void print_list(vector<int> &arr, int name)
    {
        switch(name)
        {
            case 1 : cout<<"dfs_low ";break;
            case 2 : cout<<"dfs_num ";break;
            case 3 : cout<<"parent ";break;
            case 4 : cout<<"visited ";break;
            case 5 : cout<<"is_art_pt ";break;
        }
        cout<<" | ";
        for(int i = 0; i < arr.size(); i++)
        {
            cout<<i<<" : "<<arr[i]<<" | ";
        }
        cout<<'\n';
    }
};


int main()
{
    int size, no_of_station_to_delete;
    
    cin>>size>>no_of_station_to_delete;
    
    while(size && no_of_station_to_delete)
    {
        Doves_and_Bombs obj(size, no_of_station_to_delete);
        obj.createGraph();
        // obj.printGraph();
        obj.get_res();
        cout<<'\n';
        cin>>size>>no_of_station_to_delete;
    }
    
    return 0;
}

// 6 6
// 0 1
// 1 2
// 1 4
// 4 3
// 4 5
// -1 -1
// 0 0

// 24 24
// 0 8
// 1 2
// 1 22
// 2 7
// 2 8
// 3 20
// 3 23
// 4 11
// 5 12
// 5 18
// 5 19
// 5 6
// 6 20
// 7 20
// 8 11
// 8 23
// 9 15
// 9 22
// 10 18
// 10 19
// 12 16
// 12 22
// 13 14
// 13 21
// 13 22
// 14 22
// 15 23
// 18 16
// -1 -1
// 0 0
