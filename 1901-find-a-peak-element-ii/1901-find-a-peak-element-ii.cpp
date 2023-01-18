class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans(2);
        int m = mat.size(), n = mat[0].size();
        int drow[4] = {-1, 0, 0, 1};
        int dcol[4] = {0, 1, -1, 0};
        for(int row = 0; row < m; row++){
            bool f2 = 0;
            for(int col = 0; col < n; col++){
                bool f = 1;
                for(int i = 0; i < 4; i++){
                    int r = row + drow[i], c = col + dcol[i];
                    if(r >= 0 && r < m && c >= 0 && c < n){
                        if(mat[row][col] <= mat[r][c]) f = 0;
                    }
                }
                if(f){
                    f2 = 1;
                    ans[0] = row, ans[1] = col;
                    break;
                }
            }
        }
        return ans;
    }
};