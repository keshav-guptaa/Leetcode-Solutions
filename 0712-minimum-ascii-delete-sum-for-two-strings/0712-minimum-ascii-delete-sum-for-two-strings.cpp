class Solution {
public:
    int dp[1005][1005];
    
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0, n = s1.length(), m = s2.length();
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++) ans += 97 + (s1[i]-'a');
        for(int i = 0; i < m; i++) ans += 97 + (s2[i]-'a');
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 97 + (s1[i-1]-'a') + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return ans - 2*dp[n][m];
    }
};