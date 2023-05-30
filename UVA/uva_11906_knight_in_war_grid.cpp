#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

class graph
{
    private:
    vector<vector<int>> adj;
    vector<int> hor_cord = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> ver_cord = {0, 0, 0, 0, 0, 0, 0, 0};
    const int CONTAINS_WATER = -1;
    
    public:
    
    void show_graph()
    {
        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                cout<<adj[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    
    void show_xy_shifts()
    {
        for(int i = 0; i < 8; i++)
        {
            cout<<hor_cord[i]<<' ';
        }
        cout<<'\n';
        for(int i = 0; i < 8; i++)
        {
            cout<<ver_cord[i]<<' ';
        }
        cout<<'\n';
    }
    
    graph(vector<vector<int>> &g, int hor, int ver, int m, int n)
    {
        adj = g; //new vector<vector<int>>(ver, vector<int>(hor, 0));
        
        ver_cord[0] = ver_cord[1] = hor_cord[4] = hor_cord[5] = m;
        ver_cord[2] = ver_cord[3] = hor_cord[6] = hor_cord[7] = -m;
        ver_cord[4] = ver_cord[6] = hor_cord[0] = hor_cord[2] = n;
        ver_cord[5] = ver_cord[7] = hor_cord[1] = hor_cord[3] = -n;
    }
    
    bool isSafe2(int row, int col)
    {
        if(row < 0 || row >= adj.size() || col < 0 || col >= adj[0].size())
        {
            return false;
        }
        return true;
    }
    
    void set_water(int sq_containing_water)
    {
        int x_cord = 0, y_cord = 0;
        for(int i = 0; i < sq_containing_water; i++)
        {
            cin>>x_cord>>y_cord;
            if(isSafe2(x_cord, y_cord))
            {
                adj[y_cord][x_cord] = CONTAINS_WATER;
            }
        }
    }
    
    bool isSafe(int row, int col)
    {
        if(row < 0 || row >= adj.size() || col < 0 || col >= adj[0].size()
            || adj[row][col] == CONTAINS_WATER)
        {
            return false;
        }
        return true;
    }
    
    void dfs(int row, int col)
    {
        // cout<<"dfs ran\n";
        if(!isSafe(row, col))
        {
            return;
        }
        
        if(adj[row][col] > 0)
        {
            adj[row][col]++;
            return;
        }
        
        adj[row][col]++;
        for(int i = 0; i < 8; i++)
        {
            dfs(row + ver_cord[i], col + hor_cord[i]);
        }
    }
    
    bool isEven(int num)
    {
        if(num%2)
        {
            return false;
        }
        return true;
    }
    
    ii solution()
    {
        cout<< "graph b4 dfs\n";
        show_graph();
        cout<<'\n';
        show_xy_shifts();
        
        dfs(0,0);
        
        int even_count = 0, odd_count = 0;
        adj[0][0]--;
        
        cout<< "\ngraph after dfs\n";
        show_graph();
        
        isEven(adj[0][0]) ? even_count++ : odd_count++;
        
        for(int i = 0; i < adj.size(); i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                if((i == 0 && j == 0) || adj[i][j] == CONTAINS_WATER
                    || adj[i][j] == 0)
                {
                    continue;
                }
                
                isEven(adj[i][j]) ? even_count++ : odd_count++;
            }
        }
        
        return make_pair(even_count, odd_count);
    }
};


int main()
{
    int test_case;
    cin>>test_case;
    
    for(int i = 1; i <= test_case; i++)
    {
        int hor, ver, m, n;
        cin>>hor>>ver>>m>>n;
        
        vector<vector<int>> adj(ver, vector<int>(hor, 0));
        
        int sq_containing_water = 0;
        cin>>sq_containing_water;
        
        graph g(adj, hor, ver, m, n);
        g.set_water(sq_containing_water);
        
        ii res = g.solution();
        
        cout<<"Case "<<i<<": "<<res.first<<' '<<res.second<<'\n';
    }
    return 0;
}

// tc giving wrong answer, accepted ans  = 1 4
// 1
// 9 9 3 3
// 0
