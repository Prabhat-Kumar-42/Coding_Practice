#include <iostream>
using namespace std;
#include<vector>
#include<string>

vector<int> path[27];
bool isLit[27];

void solve(int thesus, int mino, int k)
{
    int count = 0;
    
    while(true)
    {
        int next = -1;
        for(int v: path[mino])
        {
            if(!isLit[v] && v != thesus)
            {
                next = v;
                break;
            }
        }
        
        if(next == -1)
        {
            cout<<'/'<<(char)(mino + 'A')<<'\n';
            return;
        }
        
        count++;
        thesus = mino;
        mino = next;
        
        if(count == k)
        {
            cout<< (char)(thesus + 'A')<<' ';
            isLit[thesus] = true;
            count = 0;
        }
    }
}

int main()
{
    string line;
    while(getline(cin,line), line != "#")
    {
        for(int i = 0; i < 26; i++)
        {
            isLit[i] = false;
            path[i].clear();
        }
        
        int curr = line[0] - 'A';
        int pos = 2;
        
        while(line[pos] != '.')
        {
            if(line[pos] == ';')
            {
                pos++;
                curr = line[pos] - 'A';
                pos++;
            }
            else
            {
                path[curr].push_back(line[pos] - 'A');
            }
            pos++;
        }
        pos += 2;
        int mino = line[pos] - 'A'; pos+=2;
        int par = line[pos] - 'A'; pos+=2;
        
        int k = atoi(line.substr(pos).c_str());
        
        solve(par, mino, k);
    }
}