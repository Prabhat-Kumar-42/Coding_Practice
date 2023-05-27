#include <iostream>
#include <vector>

using namespace std;

class graph
{
  private:
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> indegree;
  vector<int> root;
  int dimension;
  
  public:
  
  graph(vector<vector<int>> &g, vector<bool> &vis, vector<int> &in, vector<int> &r)
  {
    adj = g;
    visited = vis;
    indegree = in;
    root = r;
    dimension = g.size();
  }
  
  void show_graph()
  {
      for(int u = 0; u < adj.size(); u++)
      {
          cout<<u<<" : ";
          for(int v = 0; v < adj[u].size(); v++)
          {
              cout<<adj[u][v]<<' ';
          }
          cout<<'\n';
      }
  }
  void show_indegree()
  {
    for(int i = 0; i < indegree.size(); i++)
    {
        cout<<"indegree of "<<i<<" = "<<indegree[i]<<'\n';
    }
  }
    
  void show_root()
  {
    for(int i = 0; i < root.size(); i++)
    {
        cout<<"root of "<<i<<" = "<<root[i]<<'\n';
    }
  }
  
  void set_connections(vector<vector<int>> &g)
  {
    for(int i = 0; i < g.size(); i++)
    {
      for(int j = 0; j < g[i].size(); j++)
      {
        cin>>g[i][j];
        if(g[i][j] == 1)
        {
            adj[i].push_back(j);
        }
      }
    }
  }
  
  void dfs(int u, int p)
  {
    visited[u] = true;
    if(u < root.size() && root[u] == -1)
    {
        root[u] = p;
    }
    for(int v : adj[u])
    {
      if(u != v)
      {
        if(v < indegree.size())
        {
            indegree[v]++;
        }
        if(v < visited.size() && !visited[v])
        {
            dfs(v, p);
        }
      }
    }
  }
  
  bool reachable_from_start_node(int v)
  {
      if(v < root.size())
      {
          return root[v] == 0;
      }
      return false;
  }
  
  void solution(vector<vector<int>> &g, int case_no)
  {
    //   show_graph();
    for(int i = 0; i < adj.size(); i++)
    {
      if(i < visited.size() && !visited[i])
      {
        dfs(i, i);
      }
    }
    
    show_indegree();
    show_root();
    vector<vector<int>> res(dimension, vector<int>(dimension, 0));
    cout<<"res: \n";
    for(int i = 0; i < g.size(); i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            if(g[i][j] == 1 && indegree[j] == 1)
            {
                res[i][j] = 1;
            }
            cout<<res[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    string s = "";
    for(int i = 0; i < dimension*2+1; i++)
    {
        if(i == 0 || i == dimension*2)
        {
            s += "+";
        }
        else
        {
                s += "-";
        }
    }
    
    // cout<<"line no : "<<line++<<"\n";
    cout<<"Case "<<case_no<<":\n";
    for(int i = 0; i < res.size(); i++)
    {
        // cout<<"line no : "<<line++<<"\n";
        cout<<s<<'\n';
        for(int j = 0; j < res[i].size(); j++)
        {
            if(reachable_from_start_node(j))
            {
                if(i == 0 || res[i][j] == 1 || i == j)
                {
                    cout<<"|Y";
                }
                else
                {
                    cout<<"|N";
                }
            }
            else
            {
                cout<<"|N";
            }
        }
        cout<<"|\n";
    }
    
    cout<<s<<'\n';
  }
  
};

int main() 
{
    int test_case;
    cin>>test_case;
    
    for(int i = 1; i <= test_case; i++)
    {
        int dimension;
        cin>>dimension;
        
        vector<vector<int>> adj(dimension, vector<int>(dimension, 0)), gp(dimension);
        vector<int> indegree(dimension, 0), root(dimension, -1);
        vector<bool>visited(dimension, false);
        
        graph g(gp, visited, indegree, root);
        g.set_connections(adj);
        g.solution(adj, i);
    }
    return 0;
}

// tc with problem
// 1
// 10
// 1 0 0 0 0 0 0 0 0 1
// 1 1 1 1 1 0 1 1 0 1
// 1 1 1 1 0 1 0 0 0 1
// 1 1 1 1 1 1 1 1 1 0
// 1 1 1 1 1 1 1 1 0 0
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 0 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1

//1
// 5
// 0 1 0 0 0
// 0 0 1 1 0 
// 0 0 0 0 1 
// 0 0 0 0 1 
// 0 0 0 0 0 
