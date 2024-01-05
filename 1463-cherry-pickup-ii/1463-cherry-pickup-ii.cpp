class Solution {
public:
    int dp[72][72][72], n, m;
    
    int f(int r, int c1, int c2, vector<vector<int>>& grid){
        if(r == n) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int ans = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int nc1 = c1 + i, nc2 = c2 + j;
                if(nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m){
                    ans = max(ans, f(r+1, nc1, nc2, grid));
                }
            }
        }
        ans += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return f(0, 0, m-1, grid);
    }
};