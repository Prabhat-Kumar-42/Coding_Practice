#include <iostream>
#include <vector>

using namespace std;

class solution
{
  private:
  vector<vector<char>> grid;
  bool black_win;
  
  int row_cord[6] = {-1, -1, 0, 0, 1, 1};
  int col_cord[6] = {-1, 0, -1, 1, 0, 1};
  
  public:
  solution(vector<vector<char>> &grid)
  {
    this->grid = grid;
    black_win = false;
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
    
  void check(int row, int col)
  {
    if(row < 0 || col < 0 || row >= grid.size() || 
    col >= grid[row].size() || grid[row][col] == 'w'
    || grid[row][col] == 'v')
    {
        return;
    }
    grid[row][col] = 'v';
    if(row == grid.size()-1)
    {
        black_win = true;
    }
    for(int i = 0; i < 6; i++)
    {
        check(row + row_cord[i], col + col_cord[i]);
        if(black_win)
        {
          return;
        }
    }
  }
  
  bool get_result()
  {
    int col = -1;
    for(int i = 0; i < grid[0].size(); i++)
    {
        if(grid[0][i] == 'b')
        {
            col = i;
            break;
        }
    }
    if(col == -1)
    {
        return false;
    }
    
    check(0, col);
    return black_win;
  }
  
};

int main()
{
    int row, count = 1;
    cin>>row;
    
    while(row)
    {
        vector<vector<char>> grid(row, vector<char>(row));
        solution obj(grid);
        
        string s;
        for(int i = 0; i < row; i++)
        {
            cin>>s;
            obj.set_row(i, s);
        }
        
        // obj.show_grid();
        if(obj.get_result())
        {
            cout<<count++<<" B\n";
        }
        else
        {
            cout<<count++<<" W\n";
        }
        cin>>row;
    }
    return 0;
}