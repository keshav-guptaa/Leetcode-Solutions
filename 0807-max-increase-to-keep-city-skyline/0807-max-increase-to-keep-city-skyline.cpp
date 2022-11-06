class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n);
        vector<int> col(m);
        int mx;
        int sum = 0;
        for(int i = 0; i < n; i++){
            mx = -1;
            for(int j = 0; j < m; j++){
                mx = max(mx, grid[i][j]);
            }
            row[i] = mx;
        }
        
        for(int j = 0; j < m; j++){
            mx = -1;
            for(int i = 0; i < n; i++){
                mx = max(mx, grid[i][j]);
            }
            col[j] = mx;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] < min(row[i], col[j])){
                    sum = sum + min(row[i], col[j]) - grid[i][j];
                }
            }
        }
        return sum;
    }
};