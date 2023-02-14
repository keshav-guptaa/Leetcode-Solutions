//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int m = 1e9+7;
    int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp){
        
    
    if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
        
        if(target == 0 || target == arr[0]) return 1;
        else return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    long long notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    long long taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%m;
    }

	public:
	int perfectSum(int num[], int n, int k)
	{
        // Your code goes here
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends