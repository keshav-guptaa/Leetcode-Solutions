class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = 0;
            } 
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
                grid[i][m-1] = 0;
            } 
        }
        
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                grid[0][j] = 0;
            } 
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
                grid[n-1][j] = 0;
            } 
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[4] = {-1, 0, 0, 1};
            int delcol[4] = {0, -1, 1, 0};
            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
        
    }
};