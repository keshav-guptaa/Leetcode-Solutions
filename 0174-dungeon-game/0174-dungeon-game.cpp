class Solution {
public:
    int f(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid, int n, int m){
        if(r >= n || c >= m) return 1e9;
        if(r == n-1 && c == m-1){
            return grid[r][c] >= 0 ? 1 : 1-grid[r][c];  
        } 
        if(dp[r][c] != -1) return dp[r][c];
        
        int right = f(r+1, c, dp, grid, n, m);
        int down = f(r, c+1, dp, grid, n, m);
        int health = min(right, down) - grid[r][c];
        return dp[r][c] = health <= 0 ? 1 : health;
    }
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, dp, grid, n, m);
    }
};