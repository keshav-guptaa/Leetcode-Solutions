class Solution {
public:
    const int mod = 1e9+7;
    int dp[50][50][51], dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
    
    int f(int r, int c, int moves, int m, int n){
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        if(moves == 0) return 0;
        if(dp[r][c][moves] != -1) return dp[r][c][moves];
        
        long long ways = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            ways += f(nr, nc, moves-1, m, n);
        }
        return dp[r][c][moves] = ways%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        return f(startRow, startColumn, maxMove, m, n);
    }
};