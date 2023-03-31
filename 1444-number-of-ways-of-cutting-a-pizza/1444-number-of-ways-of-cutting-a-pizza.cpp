class Solution {
public:
    int sf[51][51];
    int dp[51][51][11];
    const int mod = 1e9 + 7;
    
    int f(int r, int c, int k, int n, int m, int K){
        if(k == K-1) return dp[r][c][k] = 1;
        if(sf[r][c] == 0) return 0;
        
        if(dp[r][c][k] != -1) return dp[r][c][k];
        
        int ans = 0;
        
        for(int i = r+1; i < n; i++){
            if(sf[r][c] - sf[i][c]){
                ans += f(i, c, k+1, n, m, k);
                ans %= mod;
            }
        }
        
        for(int i = c+1; i < m; i++){
            if(sf[r][c] - sf[r][i]){
                ans += f(r, i, k+1, n, m, k);
                ans %= mod;
            }
        }
        return dp[r][c][k] = ans;
    }
    
    int ways(vector<string>& p, int k) {
        int n = p.size(), m = p[0].size();
        memset(dp, -1, sizeof(dp));
        memset(sf, 0, sizeof(sf));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                sf[i][j] = sf[i+1][j] + sf[i][j+1] - sf[i+1][j+1];
                sf[i][j] += p[i][j] == 'A' ? 1:0;
                
                if(sf[i][j] > 0) dp[i][j][k-1] = 1;
            }
        }
        return f(0, 0, 0, n, m, k);
    }
};