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
        dp.resize(n, vector<int>(m, -1));
        return f(n-1, m-1, grid);
    }
};