#include <iostream>
using namespace std;
#include<cstring>
#include<bits/stdc++.h>

int grid[15][15];
bool visited[15][15];
int res[15][15];
int row, col, sx, sy, dx, dy;
bool found;

void dfs(int r, int c, int count)
{
    if(r < 0 || c < 0 || r > row || c > col || visited[r][c])
    {
        return;
    }
    res[r][c] = count;
    visited[r][c] = true;
    if(c == dx && r == dy)
    {
        found = true;
        return;
    }
    if(!found && c-1 > 0 && (grid[r][c-1] != 1 && grid[r][c-1] != 3))
    {
        dfs(r, c-1, count+1);
    }
    if(!found && r-1 > 0 && (grid[r-1][c] != 2 && grid[r-1][c] != 3))
    {
        dfs(r-1, c, count+1);
    }
    if(!found && c+1 <= col && (grid[r][c] != 1 && grid[r][c] != 3))
    {
        dfs(r, c+1, count+1);
    }
    if(!found && r+1 <= row && (grid[r][c] != 2 && grid[r][c] != 3))
    {
        dfs(r+1, c, count+1);
    }
    if(!found)
    {
        res[r][c] = INT_MAX;
    }
}

void printSpace(int num)
{
    int count = 1;
    while(num >= 10)
    {
        count++;
        num/=10;
    }
    switch(count)
    {
        case 3: break;
        case 1: cout<<"  "; break;
        case 2: cout<<" "; break;
    }
}

int main()
{
    int k = 0;
    while(scanf("%d %d %d %d %d %d", &row, &col, &sy, &sx, &dy, &dx), 
            row || col || sx || sy || dx || dy)
    {
        getchar();
        k++;

        memset(grid, 0, sizeof(grid));
        memset(visited, false, sizeof(visited));
        memset(res, 0, sizeof(res));

        found = false;
        
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }
        
        dfs(sy, sx, 1);
        
        cout<<"Maze "<<k<<"\n\n";
        for(int i = 0; i < col; i++)
        {
            cout<<"+---";
        }
        cout<<"+\n";
        
        string nextLine = "";
        for(int i = 1; i <= row; i++)
        {
            nextLine.clear();
            nextLine += "+";
            for(int j = 1; j <= col; j++)
            {
                if(j == 1 || ( j > 1 && (grid[i][j-1] == 1 || grid[i][j-1] == 3)))
                {
                    cout<<'|';
                }
                else
                {
                    cout<<' ';
                }
                if(i != row)
                {
                    if((grid[i][j] == 2 || grid[i][j] == 3))
                    {
                        nextLine += "---+";
                    }
                    else
                    {
                        nextLine += "   +";
                    }
                }
                if(res[i][j] == INT_MAX)
                {
                    cout<<"???";
                }
                else if(res[i][j] == 0)
                {
                    cout<<"   ";
                }
                else
                {
                    printSpace(res[i][j]);
                    cout<<res[i][j];
                }
                if(j == col)
                {
                    cout<<'|';
                }
            }
            cout<<"\n";
            if(i != row)
            {
                cout<<nextLine<<'\n';
            }
        }
        
        for(int i = 0; i < col; i++)
        {
            cout<<"+---";
        }
        cout<<"+\n\n\n";
    }
    return 0;
}

