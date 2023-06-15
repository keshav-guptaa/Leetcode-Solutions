class Solution {
public:
    int f(int r, int c, vector<vector<int>>& dp, vector<vector<char>>& mat, int n, int m){
        if(r >= n || c >= m) return 0;
        if(mat[r][c] == '0') return 0;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = min({f(r+1, c, dp, mat, n, m), f(r+1, c+1, dp, mat, n, m), 
                               f(r, c+1, dp, mat, n, m)}) + 1;
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <  m; j++){
                ans = max(ans, f(i, j, dp, mat, n, m));
            }
        }
        return ans*ans;
    }
};