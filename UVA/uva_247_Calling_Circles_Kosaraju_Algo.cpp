#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void kosaRajuSCC(map<string, vector<string>> &circle, string current_element,
                 map<string, int> &visited, stack<string> &s)
{
    visited[current_element] = 1;
    
    for(auto i = circle[current_element].begin(); i != circle[current_element].end(); i++)
    {
        if(!visited[*i])
        {
            kosaRajuSCC(circle, *i, visited, s);
        }
    }
    s.push(current_element);
}

void printSCC(map<string, vector<string>> &transpose, string current_element,
                 map<string, int> &visited)
{
    visited[current_element] = 1;
    cout<<current_element;
    
    for(auto i = transpose[current_element].begin(); i != transpose[current_element].end(); i++)
    {
        if(!visited[*i])
        {
            cout<<", ";
            printSCC(transpose, *i, visited);
        }
    }
}

int main()
{
    int m, n;
    map<string, vector<string>> circle, transpose;
    map<string, int> visited;
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
            transpose[val].push_back(key);
        }
        
        int dfs_counter = 1;
        
        cout<<"Calling circles for data set "<<counter++<<":\n";
        
        for(auto i = circle.begin(); i != circle.end(); i++)
        {
            string current_element = i->first;
            if(!visited[current_element])
            {
                kosaRajuSCC(circle, current_element, visited, s);
            }
        }
        
        visited.clear();        
        
        while(!s.empty())
        {
            if(visited[s.top()])
            {
                s.pop();
                continue;
            }
            printSCC(transpose, s.top(), visited);
            s.pop();
            cout<<'\n';
            
        }
        
        visited.clear(); 
        circle.clear();
        transpose.clear();

        cin>>m>>n;
        if(m && n)
        {
            cout<<'\n';
        }
    }
}
