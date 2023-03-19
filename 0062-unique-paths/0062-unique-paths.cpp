class Solution {
public:
    vector<vector<int>> dp;
    int f(int r, int c){
        if(r < 0 || c < 0) return 0;
        if(r == 0 && c == 0) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = f(r-1, c) + f(r, c-1);
    }
    
    int uniquePaths(int m, int n) {
        dp.resize(n, vector<int>(m, -1));
        return f(n-1, m-1);
    }
};