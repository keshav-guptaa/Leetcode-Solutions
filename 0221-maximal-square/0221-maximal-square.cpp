class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    if(mat[i][j] == '1') dp[i][j] = 1;
                }
                else if(mat[i][j] == '1'){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                mx = max(mx, dp[i][j]);
            }
        }
        return mx*mx;
    }
};