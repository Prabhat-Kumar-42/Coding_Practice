#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int res = 0;
        int count = 0;
        map<int, int> m;
        for(int i = 0; i < N; i++)
        {
            m[arr[i]]++;
        }
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            // cout<<i->first<<' '<<i->second<<'\n';
            if(m.find(i->first + 1) != m.end())
            {
                count++;
            }
            else
            {
                count++;
                if(count > res)
                {
                    res = count;
                }
                count = 0;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code 