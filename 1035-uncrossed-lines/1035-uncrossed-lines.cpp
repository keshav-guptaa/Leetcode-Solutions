class Solution {
public:
    int dfs(vector<int>& A, vector<int>& B, int i, int j, vector<vector<int>> &dp) {
        if (i >= A.size() || j >= B.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ways = max(dfs(A, B, i+1, j, dp), dfs(A, B, i, j+1, dp));
        if(A[i] == B[j]) ways = max(ways, 1 + dfs(A, B, i+1, j+1, dp));
        return dp[i][j] = ways;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
        return dfs(A, B, 0, 0, dp);
    }
};  