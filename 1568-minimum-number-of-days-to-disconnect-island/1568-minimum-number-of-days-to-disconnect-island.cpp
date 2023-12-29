class Solution {
public:
    int dr[4] = {0, -1, 1, 0};
    int dc[4] = {1, 0, 0, -1};
    
    void dfs(vector<vector<int>>& grid, int r, int c){
        grid[r][c] = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && 
               grid[nr][nc] == 1){
                dfs(grid, nr, nc);
            }
        }
    }
    
    int count(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size(), ct = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    ct++;
                } 
            }
        }
        return ct;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int ct = count(grid);
        if(ct != 1) return 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(count(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};