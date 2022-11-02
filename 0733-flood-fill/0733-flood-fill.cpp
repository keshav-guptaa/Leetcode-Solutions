class Solution {
public:
    void dfs(int row, int col, int oldColor, int newColor, vector<vector<int>>& image, vector<vector<int>> &ans, int delrow[], int delcol[], int n, int m){
        ans[row][col] = newColor;
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, oldColor, newColor, image, ans, delrow, delcol, n, m);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {0, -1, 1, 0};
        int delcol[] = {-1, 0, 0, 1};
        int n = image.size();
        int m = image[0].size();
        dfs(sr, sc, oldColor, color, image, ans, delrow, delcol, n, m);
        return ans;
    }
};