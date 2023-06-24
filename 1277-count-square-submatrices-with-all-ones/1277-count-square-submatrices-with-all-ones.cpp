class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    res += ans[i][j];
                    continue;
                }
                if(ans[i][j] == 1) ans[i][j] = min({ans[i-1][j], ans[i][j-1], ans[i-1][j-1]})+1;
                res += ans[i][j];
            }
        }
        return res;
    }
};