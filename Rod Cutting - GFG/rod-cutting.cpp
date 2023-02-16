//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int idx, int n, int price[], vector<vector<int>> &dp){
        if(idx == 0){
            return n*price[0];
        }
        if(dp[idx][n] != -1) return dp[idx][n];
        
        int pick = INT_MIN;
        int rlen = idx+1;
        if(rlen <= n){
            pick = price[idx] + f(idx, n-rlen, price, dp);
        }
        int npick = f(idx-1, n, price, dp);
        return dp[idx][n] = max(pick, npick);
    }
    int cutRod(int price[], int n) {
        //code here

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends