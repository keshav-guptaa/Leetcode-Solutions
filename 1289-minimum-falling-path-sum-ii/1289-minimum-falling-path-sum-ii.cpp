class Solution {
public:
    int n, m;
    int dp[202][202];
    
    int f(int r, int pc, vector<vector<int>>& grid){
        if(r == n) return 0;
        if(dp[r][pc] != -1) return dp[r][pc];
        
        int mn = 1e6;
        for(int i = 0; i < m; i++){
            if(pc != i) mn = min(mn, grid[r][i] + f(r+1, i, grid));
        }
        return dp[r][pc] = mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        n = grid.size(), m = grid[0].size();
        return f(0, 201, grid);
    }
};