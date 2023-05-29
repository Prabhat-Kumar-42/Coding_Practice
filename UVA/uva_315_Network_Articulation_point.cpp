#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void createGraph(map<string, vector<string>> &network, string str)
{
    string node, key;
    stringstream ss(str);
    int first = 1;
    
    while(ss >> node)
    {
        if(first)
        {
            key = node;
            first = 0;
            continue;
        }
        network[key].push_back(node);
        network[node].push_back(key);
    }
    
}

void print_graph(map<string, vector<string>> &network)
{
    for(auto i = network.begin(); i != network.end(); i++)
    {
        cout<<i->first<<" -> ";
        for(auto j = network[i->first].begin(); j != network[i->first].end(); j++)
        {
            cout<<*j<<' ';
        }
        cout<<'\n';
    }
}

void getArticulationPoint(map<string, vector<string>> &network, map<string, int> &dfs_num, 
                         map<string, int> &dfs_low, map<string, int> &visited, string u,
                         map<string, int> &isArtPoint, map<string, string> &parent,
                         int &dfs_counter, map<string, int> &no_of_children)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    visited[u] = 1;
    
    parent[u];
    // cout<<"parent of : "<< u << " is : "<<parent[u]<<'\n';
    for(auto v = network[u].begin(); v != network[u].end(); v++)
    {
        if(!visited[*v])
        {
            // cout<<"children of : "<< u << " is : "<<*v<<'\n';
            no_of_children[u]++;
            parent[*v] = u;
            getArticulationPoint(network, dfs_num, dfs_low, visited, *v, 
                        isArtPoint, parent, dfs_counter, no_of_children/*, dfs_root*/);
            
            if(dfs_low[*v] >= dfs_num[u])
            {
                isArtPoint[u] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[*v]);
        
        }
        else if(*v != parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[*v]);
        }
    }
}

void print(map<string, int> data)
{
    for(auto i = data.begin(); i != data.end(); i++)
    {
        cout<<i->first<<'-'<<i->second<<'\n';
    }
}

int main()
{
    map<string, vector<string>> network;
    map<string, int> dfs_num, dfs_low, visited, isArtPoint, no_of_children;
    map<string, string> parent;
    int size;
    cin>>size;
    string str;
    
    while(true)
    {
        getchar();
        getline(cin, str);
        
        while(str != "0")
        {
            createGraph(network, str);
            getline(cin, str);
        }
        
        // print_graph(network);
        
        int artPoint = 0, dfs_counter = 1;
        for(auto i = network.begin(); i != network.end(); i++)
        {
            string u = i->first;
            if(!visited[u])
            {
                string dfs_root = u;
                // cout<<"ran artPoint for "<< u <<"\n";
                getArticulationPoint(network, dfs_num, dfs_low, visited, u, 
                            isArtPoint, parent, dfs_counter, no_of_children);
                isArtPoint[u] = no_of_children[u] > 1;
            }
        }
        
        
        for(auto i = isArtPoint.begin(); i != isArtPoint.end(); i++)
        {
            if(i->second)
            {
                artPoint++;
            }
        }
        
        // cout<<"dfs_num\n";
        // print(dfs_num);
        // cout<<"dfs_low\n";
        // print(dfs_low);
        // cout<<"isArtPoint\n";
        // print(isArtPoint);
        // cout<<"no_of_children\n";
        // print(no_of_children);
        
        // cout<<"no_of_artPoint\n";
        cout<<artPoint<<'\n';
        
        network.clear();
        dfs_num.clear();
        dfs_low.clear();
        visited.clear();
        parent.clear();
        isArtPoint.clear();
        no_of_children.clear();
        
        cin>>size;
        if(!size)
        {
            break;
        }
    }
}