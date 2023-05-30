#include <iostream>
using namespace std;
#include<vector>
class flatWorld
{
    int north = 0, west = 1, south = 2, east = 3;
    int fall = 1;
   
    public:
    int get_dir(char dir)
    {
        if(dir == 'N')
        {
            return 0;
        }
        if(dir == 'W')
        {
            return 1;
        }
        if(dir == 'S')
        {
            return 2;
        }
        if(dir == 'E')
        {
            return 3;
        }
        return -1;
    }
    
    void print_dir(int dir)
    {
        if(dir == 0)
        {
            cout<<'N';
        }
        if(dir == 1)
        {
            cout<<'W';
        }
        if(dir == 2)
        {
            cout<<'S';
        }
        if(dir == 3)
        {
            cout<<'E';
        }
    }
    
    void print_res(int x, int y, int dir, bool isLost)
    {
        // isResPrinted = true;
        cout<<x<<' '<<y<<' ';
        print_dir(dir);
        if(isLost)
        {
            cout<<" LOST";
        }
        cout<<'\n';
    }
    
    bool isSafe(int x, int y, int row, int col)
    {
        if(x < 0 || y < 0 || x >= col || y >= row)
        {
            return false;
        }
        return true;
    }
    
    void movements(vector<vector<int>> &grid, int row, int col,
                    int x, int y, int initial_dir, string &command, int &si)
    {
        // cout<<"si = "<<si<<" : \n";
        int left = 0, right = 0;
        
        while(si < command.size() && command[si] != 'F')
        {
            if(command[si] == 'R')
            {
                right--;
            }
            else if(command[si] == 'L')
            {
                left++;
            }
            si++;
        }
        
        // cout<<"si = "<<si<<'\n';
        left = left%4;
        right = -(-right%4);
        
        int curr_dir = initial_dir + left + right;
        curr_dir = ((curr_dir + 4)%4 + 4)%4;
        
        // cout<<"left = "<<left<<" right = "<<right<<" curr_dir = "<<curr_dir<<' ';
        // print_dir(curr_dir);
        // cout<<'\n';
        
        if(si >= command.size())
        {
            print_res(x, y, curr_dir, false);
            return;
        }
        
        bool isLost = false;
        if(curr_dir == north)
        {
            if(isSafe(x, y+1, row, col))
            {
                y++;
            }
            else if(grid[y][x] != fall)
            {
                isLost = true;
                grid[y][x] = fall;
            }
        }
        else if(curr_dir == south)
        {
            if(isSafe(x, y-1, row, col))
            {
                y--;
            }
            else if(grid[y][x] != fall)
            {
                isLost = true;
                grid[y][x] = fall;
            }
        }
        else if(curr_dir == east)
        {
            if(isSafe(x+1, y, row, col))
            {
                x++;
            }
            else if(grid[y][x] != fall)
            {
                isLost = true;
                grid[y][x] = fall;
            }
        }
        else if(curr_dir == west)
        {
            if(isSafe(x-1, y, row, col))
            {
                x--;
            }
            else if(grid[y][x] != fall)
            {
                isLost = true;
                grid[y][x] = fall;
            }
        }
        
        // cout<<"isLost = "<<isLost<<'\n';
        // cout<<"x = "<<x<<" y = "<<y;
        // cout<<"\n";
        if(isLost || si == command.size() - 1)
        {
            print_res(x, y, curr_dir, isLost);
        }
        else
        {
            si++;
            movements(grid, row, col, x, y, curr_dir, command, si);
        }
        
    }
};
int main() 
{
    int col, row;
    cin>>col>>row;
    // cout<<row<<' '<<col<<'\n';
    row++, col++;
    vector<vector<int>> grid(row, vector<int> (col, 0));
    int x, y;
    while(scanf("%d %d", &x, &y) == 2)
    {
        
        char dir;
        cin>>dir;
        
        string command;
        cin>>command;
        
        flatWorld obj;
        int curr_dir = obj.get_dir(dir), si = 0;
        
        // cout<<x<<' '<<y<<' '<<dir<<' '<<curr_dir<<' '<<command<<"\n";
        
        obj.movements(grid, row, col, x, y, curr_dir, command, si);
        // cout<<'\n';
    }
}