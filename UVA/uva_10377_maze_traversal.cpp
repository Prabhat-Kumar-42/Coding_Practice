#include <iostream>
#include <vector>
using namespace std;


class solution
{
    private:
    vector<vector<char>> grid;
    int row, col;
    char curr_dir;
    
    public:
    solution(vector<vector<char>> &grid)
    {
        this->grid = grid;
        curr_dir = 'N';
    }
    
    void set_row_col(int row, int col)
    {
        this->row = row-1;
        this->col = col-1;
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
                }
            }
        }
    }
    
    void change_direction(char dir)
    {
        if(dir == 'R')
        {
            if(curr_dir == 'N')
            {
                curr_dir = 'E';
            }
            else if(curr_dir == 'E')
            {
                curr_dir = 'S';
            }
            else if(curr_dir == 'S')
            {
                curr_dir = 'W';
            }
            else if(curr_dir == 'W')
            {
                curr_dir = 'N';
            }
        }
        else if(dir == 'L')
        {
            if(curr_dir == 'N')
            {
                curr_dir = 'W';
            }
            else if(curr_dir == 'W')
            {
                curr_dir = 'S';
            }
            else if(curr_dir == 'S')
            {
                curr_dir = 'E';
            }
            else if(curr_dir == 'E')
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
                if(grid[row - 1][col] != '*')
                {
                    row = row - 1;
                }
            }
        }
        else if(curr_dir == 'E')
        {
            if(col + 1 < grid[0].size())
            {
                if(grid[row][col + 1] != '*')
                {
                    col = col + 1;
                }
            }
        }
        else if(curr_dir == 'S')
        {
            if(row + 1 < grid.size())
            {
                if(grid[row + 1][col] != '*')
                {
                    row = row + 1;
                }
            }
        }
        else if(curr_dir == 'W')
        {
            if(col - 1 >= 0)
            {
                if(grid[row][col - 1] != '*')
                {
                    col = col - 1;
                }
            }
        }
        
    }
    
    void follow_command(char command)
    {
        if(command == 'R' || command == 'L')
        {
            // cout<<"dir changed : prev_dir = "<<curr_dir<<" ";
            change_direction(command);
            // cout<<"new_dir = "<<curr_dir<<'\n';
        }
        else
        {
            // cout<<"prev_cord : row = "<<row+1<<" col = "<<col+1<<'\n';
            move_robot();
            // cout<<"new_cord : row = "<<row+1<<" col = "<<col+1<<'\n';
        }
    }
    
    void get_result()
    {
        cout<<row+1<<' '<<col+1<<' '<<curr_dir<<'\n';
    }
};


int main()
{
    int test_case;
    cin>>test_case;
    
    while(test_case--)
    {
        int row, col;
        cin>>row>>col;
        vector<vector<char>> grid(row, vector<char>(col));
        solution obj(grid);
        
        string s;
        char x;
        scanf(" %c", x);
        for(int i = 0; i < row; i++)
        {
            getline(cin, s);
            obj.set_row(i, s);
        }
        // obj.show_grid();
        
        int initial_row, initial_col;
        cin>>initial_row>>initial_col;
        
        obj.set_row_col(initial_row, initial_col);
        
        // obj.get_result();
        
        char command;
        cin>>command;
        while(command != 'Q')
        {
            // cout<<command<<'\n';
            if(command == 'L' || command == 'R' || command == 'F')
            {
                obj.follow_command(command);
            }
            cin>>command;
        }
        
        obj.get_result();
        if(test_case)
        {
            cout<<'\n';
        }
    }
}