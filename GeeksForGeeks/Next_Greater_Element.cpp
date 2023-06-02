#include <stack>
using namespace std;

typedef long long llint;

int main()
{
    int test_case;
    cin>>test_case;
    
    while(test_case--)
    {
        llint size;
        cin>>size;
        
        llint* arr = new llint[size];
        llint* res = new llint[size];
        
        stack<llint> s;
        
        for(llint i = 0; i < size; i++)
        {
            cin>>arr[i];
            while(!s.empty() && arr[s.top()] < arr[i])
            {
                res[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            res[s.top()] = -1;
            s.pop();
        }
        
        for(llint i = 0; i < size; i++)
        {
            if(res[i] != -1)
            {
                cout<<arr[res[i]]<<' ';
            }
            else
            {
                cout<<res[i]<<' ';
            }
        }
        
        delete arr;
        delete res;
        cout<<'\n';
    }
	return 0;
}