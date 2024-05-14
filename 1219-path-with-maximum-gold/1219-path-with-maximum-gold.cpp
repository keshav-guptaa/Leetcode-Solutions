class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
    int f(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) return 0;
        int val = grid[r][c];
        grid[r][c] = 0;
        int ans = val, mx = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            mx = max(mx, f(nr, nc, grid));
        }
        grid[r][c] = val;
        return val + mx;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, f(i, j, grid));
            }
        }
        return ans;
    }
};