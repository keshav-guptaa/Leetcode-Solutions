class Solution {
public:
    int f(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp,
         int n){
        int c2 = (r1+c1)-r2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if(r2 == n-1 && c2 == n-1) return grid[r2][c2];
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        
        int ch = 0;
        if(r1 == r2 && c1 == c2) ch += grid[r1][c1];
        else ch += grid[r1][c1] + grid[r2][c2];
        
        int rr = f(r1, c1+1, r2, grid, dp, n);
        int rd = f(r1, c1+1, r2+1, grid, dp, n);
        int dr = f(r1+1, c1, r2, grid, dp, n);
        int dd = f(r1+1, c1, r2+1, grid, dp, n);
        ch += max(max(rr, rd), max(dr, dd));
        return dp[r1][c1][r2] = ch;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = f(0, 0, 0, grid, dp, n);
        return ans < 0 ? 0 : ans;
    }
};
