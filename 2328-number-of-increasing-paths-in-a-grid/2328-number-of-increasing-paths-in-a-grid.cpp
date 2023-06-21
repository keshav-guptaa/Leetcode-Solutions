class Solution {
public:
    const int mod = 1e9 + 7;
    
    int dr[4] = {0, -1, 1, 0};
    int dc[4] = {-1, 0, 0, 1};
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[r][c] != -1) return dp[r][c];
        long ans = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && 
                grid[r][c] < grid[nr][nc]){
                ans = (ans + dfs(nr, nc, grid, dp))%mod;
            }  
        }
        return dp[r][c] = ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        long ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += dfs(i, j, grid, dp);
                ans %= mod;
            }
        }
        return ans;
    }
};