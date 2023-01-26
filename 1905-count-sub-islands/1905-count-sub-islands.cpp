class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m, int drow[], int dcol[], int &f){
        grid2[i][j] = 0;
        if(grid1[i][j] == 0) f = 0;
        for(int k = 0; k < 4; k++){
            int nrow = drow[k] + i;
            int ncol = j + dcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid2[nrow][ncol] == 1){
                dfs(nrow, ncol, grid1, grid2, n, m, drow, dcol, f);
            }
        }
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(), m = grid2[0].size(), ct = 0;
        int drow[] = {-1, 0, 0, 1}, dcol[] = {0, -1, 1, 0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1){
                    int f = 1;
                    dfs(i, j, grid1, grid2, n, m, drow, dcol, f);
                    ct += f;
                } 
            }
        }
        return ct;
    }
};