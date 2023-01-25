class Solution {
public:
    void dfs1(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0){
            grid[i][j] = 1;
            dfs1(i, j-1, grid, n, m);
            dfs1(i, j+1, grid, n, m);
            dfs1(i+1, j, grid, n, m);
            dfs1(i-1, j, grid, n, m);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0) dfs1(i, 0, grid, n, m);
            if(grid[i][m-1] == 0) dfs1(i, m-1, grid, n, m);
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 0) dfs1(0, j, grid, n, m);
            if(grid[n-1][j] == 0) dfs1(n-1, j, grid, n, m);
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs1(i, j, grid, n, m);
                }
            }
        }
        return cnt;
    }
};