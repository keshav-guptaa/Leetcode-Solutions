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
        vector<vector<int>> dp(x, vector<int>(n+1, -1));
        
        return f(x-1, n, sq, dp);
    }
};