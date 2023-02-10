//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int memo(int idx, vector<int>& h, vector<int>& dp){
        if(idx == 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int j1 = memo(idx-1, h, dp) + abs(h[idx]-h[idx-1]);
        int j2 = INT_MAX;
        if(idx > 1) j2 = memo(idx-2, h, dp) + abs(h[idx]-h[idx-2]);
        
        return dp[idx] = min(j1, j2);
    }
    
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        vector<int> dp(n+1, -1);
        return memo(n-1, h, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends