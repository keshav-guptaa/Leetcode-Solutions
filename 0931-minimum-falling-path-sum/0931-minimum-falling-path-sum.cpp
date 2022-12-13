class Solution {
public:
    int memoization(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        if(j<0 || j>=matrix.size()) return 1e9;
        if(i == 0) return matrix[0][j];
        if(j<0 || j>=matrix.size()) return 1e9;
        if(dp[i][j] != 1e9) return dp[i][j];
        
        int up = matrix[i][j] + memoization(i-1,j,dp,matrix);
        int leftD = matrix[i][j] + memoization(i-1,j-1,dp,matrix);
        int rightD = matrix[i][j] + memoization(i-1,j+1,dp,matrix);
        
        return dp[i][j] = min(up,min(leftD,rightD));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        /* int mn = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        
        for(int j=0; j<m; j++){
            int ans = memoization(n-1, j, dp, matrix);
            mn = min(mn,ans);
        }
        return mn;
        */
        
        
        // tabulation
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                
                int up = matrix[i][j] + dp[i-1][j];
                
                int leftD = matrix[i][j];
                if(j-1 >= 0) leftD += dp[i-1][j-1];
                else leftD += 1e9;
                
                int rightD = matrix[i][j];
                if(j+1 < n) rightD += dp[i-1][j+1];
                else rightD += 1e9;
                
                dp[i][j] = min(up,min(rightD, leftD));
                
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans,dp[n-1][j]);
        }
        
        return ans;
        
        
    }
};