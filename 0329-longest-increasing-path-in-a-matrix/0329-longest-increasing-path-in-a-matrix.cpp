class Solution {
public:
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, 1, -1, 0};
    
    int dfs(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& mat, int n, int m){
        if(dp[r][c] != -1) return dp[r][c];
        int mx = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] > mat[r][c]){
                mx = max(mx, 1 + dfs(nr, nc, dp, mat, n, m));
            }
        }
        return dp[r][c] = mx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(i, j, dp, mat, n, m));
            }
        }
        return ans;
    }
};