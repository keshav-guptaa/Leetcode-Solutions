//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9+7;
  
    int f(int idx, int target, vector<vector<int>>& dp, vector<int>& arr){
        if(idx == 0){
            if(target == 0 && arr[0] == 0) return 2;
            else if(target == 0 || target == arr[0]) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        long long ways = 0;
        ways += f(idx-1, target, dp, arr);
        if(arr[idx] <= target) ways += f(idx-1, target-arr[idx], dp, arr);
        ways %= mod;
        return dp[idx][target] = ways;
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        if(sum-d < 0) return 0;
        if((sum-d)&1) return 0;
        int target = (sum-d)/2;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, dp, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends