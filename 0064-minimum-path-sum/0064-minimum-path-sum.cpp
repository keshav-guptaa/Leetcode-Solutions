class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || c < 0) return 1e9;
        if(r == 0 && c == 0) return grid[0][0];
        if(dp[r][c] != -1) return dp[r][c];
        
        int up = f(r-1, c, grid);
        int left = f(r, c-1, grid);
        return dp[r][c] = grid[r][c] + min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<int>(m, 0));
        
        dp[0][0] = grid[0][0];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                int up = 0;
                if(i >= 1) up = dp[i-1][j];
                else up = 1e9;
                int left = 0;
                if(j >= 1) left = dp[i][j-1];
                else left = 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
        
        return dp[n-1][m-1];
    }
};