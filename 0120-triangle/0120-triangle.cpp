class Solution {
public:
    int f(int r, int c, vector<vector<int>>& t, vector<vector<int>>& dp){
        if(r == t.size()) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        
        int down = t[r][c] + f(r+1, c, t, dp);
        int di = t[r][c] + f(r+1, c+1, t, dp);
        return dp[r][c] = min(di, down);
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, t, dp);
    }
};