//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int FindMaxSum(int arr[], int size)
    {
        // Your code here
        vector<int>dp(size,0);

        dp[0]=arr[0];

        int incl=0;

        for(int n=1;n<size;n++){

            if(n-2>=0) incl=arr[n]+dp[n-2];

            else incl=arr[n];

        

        int excl=0+dp[n-1];

        dp[n]=max(incl,excl);

    

            

        }

      return dp[size-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends