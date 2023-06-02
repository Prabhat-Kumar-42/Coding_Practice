#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
    int count = 0;
    
    for(int i =0; i < n; i++)
    {
        if(i-1 < 0)
        {
            if(arr[i] > arr[i+1])
            {
                return i;
            }

        }
        else if(arr[i] > arr[i+1] && arr[i] > arr[i-1])
        {
            return i;
        }
        
    }
    
    return -1; // Your code here
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}