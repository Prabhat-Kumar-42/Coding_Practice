#include <iostream>
#include <vector>
using namespace std;


class solution
{
    private:
    vector<vector<char>> grid;
    int row, col;
    char curr_dir;
    int res;
    
    public:
    solution(vector<vector<char>> &grid)
    {
        this->grid = grid;
        res = 0;
    }
    
    void show_grid()
    {
        for(int i = 0; i < grid.size(); i++)
        {
            for(char ch : grid[i])
            {
                cout<<ch;
            }
            cout<<'\n';
        }
    }
    
    void set_row(int i, string &s)
    {
        if(i < grid.size())
        {
            if(s.size() == grid[i].size())
            {
                for(int j = 0; j < s.size(); j++)
                {
                    grid[i][j] = s[j];
                    if(s[j] != '.' && s[j] != '*' && s[j] != '#')
                    {
                        row = i, col = j;
                        curr_dir = s[j];
                    }
                }
            }
        }
    }
    
    
    void change_direction(char dir)
    {
        if(dir == 'D')
        {
            if(curr_dir == 'N')
            {
                curr_dir = 'L';
            }
            else if(curr_dir == 'L')
            {
                curr_dir = 'S';
            }
            else if(curr_dir == 'S')
            {
                curr_dir = 'O';
            }
            else if(curr_dir == 'O')
            {
                curr_dir = 'N';
            }
        }
        else if(dir == 'E')
        {
            if(curr_dir == 'N')
            {
                curr_dir = 'O';
            }
            else if(curr_dir == 'O')
            {
                curr_dir = 'S';
            }
            else if(curr_dir == 'S')
            {
                curr_dir = 'L';
            }
            else if(curr_dir == 'L')
            {
                curr_dir = 'N';
            }
        }
    }
    
    void move_robot()
    {
        if(curr_dir == 'N')
        {
            if(row - 1 >= 0)
            {
                if(grid[row - 1][col] != '#')
                {
                    row = row - 1;
                }
            }
        }
        else if(curr_dir == 'L')
        {
            if(col + 1 < grid[0].size())
            {
                if(grid[row][col + 1] != '#')
                {
                    col = col + 1;
                }
            }
        }
        else if(curr_dir == 'S')
        {
            if(row + 1 < grid.size())
            {
                if(grid[row + 1][col] != '#')
                {
                    row = row + 1;
                }
            }
        }
        else if(curr_dir == 'O')
        {
            if(col - 1 >= 0)
            {
                if(grid[row][col - 1] != '#')
                {
                    col = col - 1;
                }
            }
        }
        
        if(grid[row][col] == '*')
        {
            res++;
            grid[row][col] = '.';
        }
    }
    
    void follow_command(char command)
    {
        if(command == 'D' || command == 'E')
        {
            // cout<<"dir changed : prev_dir = "<<curr_dir<<" ";
            change_direction(command);
            // cout<<"new_dir = "<<curr_dir<<'\n';
        }
        else
        {
            move_robot();
        }
    }
    
    int get_result()
    {
        return res;
    }
};


int main()
{
    int N, M, S;
    cin>>N>>M>>S;
    
    while(N || M || S)
    {
        vector<vector<char>> grid(N, vector<char>(M));
        solution obj(grid);
        
        string s;
        for(int i = 0; i < N; i++)
        {
            cin>>s;
            obj.set_row(i, s);
        }
        
        // obj.show_grid();
        
        while(S--)
        {
            char command;
            cin>>command;
            // cout<<command<<'\n';
            obj.follow_command(command);
        }
        
        cout<<obj.get_result()<<'\n';
        cin>>N>>M>>S;
    }
}