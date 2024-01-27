class Solution {
public:
    int mod = 1e9+7;
    
    int f(int n, int k, vector<vector<int>>& dp){
        if(k <= 0) return k == 0;
        if(dp[n][k] != -1) return dp[n][k];
        
        int ways = 0;
        for(int i = 0; i <= k && i < n; i++){
            ways = (ways + f(n-1, k-i, dp)) % mod;
        } 
        return dp[n][k] = ways;
    }
    
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        // dp[0][0] = 1;
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 0; j <= k; j++){
        //         for(int l = 0; l <= min(j, i-1); l++){
        //             dp[i][j] = (dp[i][j] + dp[i-1][j-l])%mod;
        //         }
        //     }
        // }
        return f(n, k, dp);
    }
};