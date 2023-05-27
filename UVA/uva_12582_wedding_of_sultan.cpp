#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solve(vector<int> &sprinkler, string &s)
{
    stack<char> stk;
    for(char ch : s)
    {
        if(stk.empty() || ch != stk.top())
        {
            stk.push(ch);
        }
        else if(ch == stk.top())
        {
            stk.pop();
            if(!stk.empty())
            {
                sprinkler[ch - 'A']++;
                sprinkler[stk.top() - 'A']++;
            }
        }
    }
    
    while(!stk.empty())
    {
        sprinkler[stk.top() - 'A']++;
        stk.pop();
    }
    
    return 0;
}

int main() {
    int testcase;
    cin>>testcase;
    
    for(int i = 0; i < testcase; i++)
    {
        string s;
        cin>>s;
        vector<int> sprinkler(26, 0);
        
        int fail = solve(sprinkler, s);
        
        if(!fail)
        {
            cout<<"Case "<<i+1<<'\n';
                    
            for(int j = 0; j < 26; j++)
            {
                if(sprinkler[j])
                {
                    cout<<(char)(j + 'A')<<" = "<<sprinkler[j]<<'\n';
                }
            }
        }
        else
        {
            cout<<"failed\n";
        }
    }
    return 0;
}