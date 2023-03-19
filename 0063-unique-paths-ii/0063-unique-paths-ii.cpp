class Solution {
public:
    vector<vector<int>> dp;
    int f(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || c < 0) return 0;
        if(grid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = f(r-1, c, grid) + f(r, c-1, grid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        if(grid[n-1][m-1] == 1) return 0;
        dp.resize(n, vector<int>(m, -1));
        return f(n-1, m-1, grid);
    }
};