class Solution {
public:
    const int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                for(int l = 0; l <= min(j, i-1); l++){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-l])%mod;
                }
            }
        }
        return dp[n][k];
    }
};