//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int idx, int len, vector<vector<int>>& dp, int price[]){
        if(len == 0) return 0;
        if(idx == 0) return price[0]*len;
        if(dp[idx][len] != -1) return dp[idx][len];
        
        int pick = 0;
        if(idx+1 <= len) pick = price[idx] + f(idx, len-idx-1, dp, price);
        int npick = f(idx-1, len, dp, price);
        
        return dp[idx][len] = max(pick, npick);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, dp, price);
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