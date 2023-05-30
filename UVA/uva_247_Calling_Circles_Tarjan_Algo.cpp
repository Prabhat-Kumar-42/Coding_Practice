#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void tarjan(map<string, vector<string>> &circle, string current_element,
            map<string, int> &dfs_num, map<string, int> &dfs_low,
            map<string, int> &visited, stack<string> &s, int* dfs_counter)
{
    dfs_num[current_element] = dfs_low[current_element] = (*dfs_counter)++;
    s.push(current_element);
    visited[current_element] = 1;
    
    for(auto i = circle[current_element].begin(); i != circle[current_element].end(); i++)
    {
        if(!visited[*i])
        {
            tarjan(circle, *i, dfs_num, dfs_low, visited, s, dfs_counter);
        }
        dfs_low[current_element] = min(dfs_low[current_element], dfs_low[*i]);
    }
    
    if(dfs_low[current_element] == dfs_num[current_element])
    {
        while(s.top() != current_element)
        {
            cout<<s.top()<<' ';
            s.pop();
        }
        cout<<s.top()<<' ';
        s.pop();
        cout<<'\n';
    }
}

void clearStack(stack<string> &s)
{
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
}

int main()
{
    int m, n;
    map<string, vector<string>> circle;
    map<string, int> dfs_num, dfs_low, visited;
    stack<string> s;
    string key, val;
    
    cin>>m>>n;
    int counter = 1;
    
    while(m!=0 && n!=0)
    {
        while(n--)
        {
            cin>>key>>val;
            circle[key].push_back(val);
        }
        
        int dfs_counter = 1;
        
        cout<<"Calling circles for data set "<<counter++<<":\n";
        
        for(auto i = circle.begin(); i != circle.end(); i++)
        {
            string current_element = i->first;
            if(!visited[current_element])
            {
                tarjan(circle, current_element, dfs_num, dfs_low, visited, s, &dfs_counter);
            }
        }
        
        clearStack(s);
        circle.clear();
        dfs_low.clear();
        dfs_num.clear();
        visited.clear();
        cout<<'\n';
        
        cin>>m>>n;
    }
}