class Solution {
public:
    int f(int idx, int tot, vector<int>& sq, vector<vector<int>> &dp){
        if(tot == 0) return 0;
        if(idx < 0) return 1e9;
        if(dp[idx][tot] != -1) return dp[idx][tot];
        
        int pick = 1e9;
        if(sq[idx] <= tot) pick = 1 + f(idx, tot-sq[idx], sq, dp);
        int npick = f(idx-1, tot, sq, dp);
        return dp[idx][tot] = min(pick, npick);
    }
    
    int numSquares(int n) {
        vector<int> sq;
        int i = 1;
        while(i*i <= n){
            sq.push_back(i*i);
            i++;
        }
        int x = sq.size();
        vector<vector<int>> dp(x+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; i++) dp[0][i] = 1e9;
        
        for(int idx = 1; idx <= x; idx++){
            for(int tot = 1; tot <= n; tot++){
                int pick = 1e9;
                if(sq[idx-1] <= tot) pick = 1 + dp[idx][tot-sq[idx-1]];
                int npick = dp[idx-1][tot];
                dp[idx][tot] = min(pick, npick);
            }
        }
        
        return dp[x][n];
    }
};