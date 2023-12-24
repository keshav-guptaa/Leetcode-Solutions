class Solution {
public:
    int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0}; 
    
    void dfs(int r, int c, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        grid[r][c] = 2;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                dfs(nr, nc, grid);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool f = 0;
        for(int i = 0; i < n; i++){
            if(f) break;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    f = 1;
                    dfs(i, j, grid);
                    break;
                }
            }
        }
        queue<pair<int, int>> q;
        //int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j] << " ";
                if(grid[i][j] == 2){
                    q.push({i, j});
                } 
            }
            cout << endl;
        }
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(grid[nr][nc] == 1) return grid[r][c] - 2;
                    if(grid[nr][nc] == 0){
                        grid[nr][nc] = 1 + grid[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};