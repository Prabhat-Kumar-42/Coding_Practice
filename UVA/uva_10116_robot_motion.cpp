#include <iostream>
#include<vector>
using namespace std;

class solution
{
    private:
    vector<vector<char>> grid;
    vector<vector<int>> visited;
    int row, col;
    int res, loop_res;
    
    public:
    solution(vector<vector<char>> &grid, vector<vector<int>> &visited, int col)
    {
        this->grid = grid;
        this->visited = visited;
        this->col = col-1;
        row = 0;
        res = loop_res = 0;
    }
    
    void set_row(int i, string &s)
    {
        if(i < grid.size())
        {
            if(s.size() == grid[i].size())
            {
                for(int j = 0; j < grid[i].size(); j++)
                {
                    grid[i][j] = s[j];
                }
            }
        }
    }
    
    void show_grid()
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                cout<<grid[i][j];
            }
            cout<<'\n';
        }
    }
    
    void move_robot(int row, int col)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        {
            return;
        }
        res++;
        if(visited[row][col])
        {
            loop_res = res - visited[row][col];
            res = visited[row][col] - 1;
            return;
        }
        visited[row][col] = res;
        if(grid[row][col] == 'N')
        {
            // cout<<"moved north\n";
            move_robot(row-1, col);
        }
        else if(grid[row][col] == 'E')
        {
            // cout<<"moved east\n";
            move_robot(row, col+1);
        } 
        else if(grid[row][col] == 'S')
        {
            // cout<<"moved south\n";
            move_robot(row+1, col);
        }
        else if(grid[row][col] == 'W')
        {
            // cout<<"moved west\n";
            move_robot(row, col-1);
        } 
    }
    
    void get_result()
    {
        move_robot(row, col);
        if(loop_res)
        {
            cout<<res<<" step(s) before a loop of "<<loop_res<<" step(s)\n";
        }
        else
        {
            cout<<res<<" step(s) to exit\n";
        }
    }
};

int main()
{
    int row, col, initial_col;
    cin>>row>>col>>initial_col;
    
    while(row || col || initial_col)
    {
        vector<vector<char>> grid(row, vector<char>(col));
        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        solution obj(grid, visited, initial_col);
        
        string s;
        for(int i = 0; i < row; i++)
        {
            cin>>s;
            obj.set_row(i, s);
        }
        obj.get_result();
        cin>>row>>col>>initial_col;
    }
    return 0;
}