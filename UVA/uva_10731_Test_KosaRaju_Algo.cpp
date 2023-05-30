#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void createGraph(map<char, vector<char>> &dict,
                 map<char, vector<char>> &transpose,
                 vector<char> input)
{
    char key = input[5];
    
    for(int i = 0; i < 5; i++)
    {
        dict[key].push_back(input[i]);
        transpose[input[i]].push_back(key);
    }
}

void kosarajuSCC(map<char, vector<char>> &dict,
                map<char, int> &visited, stack<char> &stk, 
                char current_node)
{
    visited[current_node] = 1;
    
    for(auto i = dict[current_node].begin(); i != dict[current_node].end(); i++)
    {
        if(!visited[*i])
        {
            kosarajuSCC(dict, visited, stk, *i);
        }
    }
    stk.push(current_node);
}


void getSCC(map<char, vector<char>> &transpose, map<char, int> &visited,
            vector<char> &SCC, char current_node)
{
    visited[current_node] = 1;
    SCC.push_back(current_node);
    
    for(auto i = transpose[current_node].begin(); i != transpose[current_node].end(); i++)
    {
        if(!visited[*i])
        {
            getSCC(transpose, visited, SCC, *i);
        }
    }
}    


// void printResult(vector<vector<char>> &result)
// {
//     vector<char>* res = NULL;
    
//     for(int i = 0; i < result.size(); i++)
//     {
//         if(result[i].size() > 1)
//         {
//             if(res == NULL)
//             {
//                 res = &result[i];
//             }
//             else if(result[i].size() < (*res).size())
//             {
//                 res = &result[i];
//             }
//         }
//     }
    
//     sort((*res).begin(), (*res).end());
    
//     cout<<(*res).size()<<'\n';
//     for(int i = 0; i < (*res).size(); i++)
//     {
//         cout<<(*res)[i];
//         if(i < (*res).size() - 1)
//         {
//             cout<<' ';
//         }
//     }
// }

void printResult(vector<vector<char>> &result)
{
    for(int i = 0; i < result.size(); i++)
    {
        if(result[i].size() > 1)
        {
            sort(result[i].begin(), result[i].end());
        }
    }
    
    sort(result.begin(), result.end());
    
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j];
            if(j != result[i].size()-1)
            {
                cout<<' ';
            }
        }
        cout<<'\n';
    }
}

int main()
{
    int n;
    cin>>n;
    if(!n)
    {
        return 0;
    }
    
    
    map<char, vector<char>> dict, transpose;
    map<char, int> visited;
    stack<char> stk;
    
    vector<char> input(6);
    vector<vector<char>> result;
    vector<char> SCC;
    
    while(true)
    {
        getchar();
        while(n--)
        {
            for(int i = 0; i < 6; i++)
            {
                cin>>input[i];
            }
            
            createGraph(dict, transpose, input); // create graph and it's transpose
        }
        
        //Kosaraju_Algo Start here
        for(auto i = dict.begin(); i != dict.end(); i++)
        {
            char current_node = i->first;
            if(!visited[current_node])
            {
                kosarajuSCC(dict, visited, stk, current_node);
            }
        }
        
        visited.clear();        
        while(!stk.empty())
        {
            if(visited[stk.top()])
            {
                stk.pop();
                continue;
            }
            
            getSCC(transpose, visited, SCC, stk.top());
            stk.pop();
            result.push_back(SCC);
            SCC.clear();
        }
        //Kosaraju_Algo End here
        
        printResult(result);
        
        dict.clear();
        transpose.clear();
        visited.clear();
        result.clear();
        
        cin>>n;
    
        if(n)
        {  
            cout<<'\n';
        }
        else
        {
            break;
        }
    }
}