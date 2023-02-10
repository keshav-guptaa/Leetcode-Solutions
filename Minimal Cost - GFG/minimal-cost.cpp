//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int memo(int idx, vector<int>& h, vector<int>& dp, int k){
        if(idx == 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int mn = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(idx >= j){
                mn = min(mn, memo(idx - j, h, dp, k) + abs(h[idx-j] - h[idx]));
            }
        }
        return dp[idx] = mn;
    }
  
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        vector<int> dp(n, -1);
        dp[0] = 0;
        int mn = INT_MAX;
        
        for(int idx = 1; idx < n; idx++){
            int mn = INT_MAX;
            for(int j = 1; j <= k; j++){
                if(idx >= j){
                   mn = min(mn, memo(idx - j, h, dp, k) + abs(h[idx-j] - h[idx]));
                }
            }
            dp[idx] = mn;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends