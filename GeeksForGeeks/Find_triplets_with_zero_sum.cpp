#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool check(int* arr, int l, int r, int sum)
    {
        while(l < r)
        {
            if(arr[l]+arr[r] == sum)
            {
                return true;
            }
            else if(arr[l]+arr[r] < sum)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false;
    }
    
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        for(int i = 0; i < n-1; i++)
        {
            if(check(arr, i+1, n-1, -arr[i]))
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends
