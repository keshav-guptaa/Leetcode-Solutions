class Solution {
public:
    int f(int idx, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(walls <= 0) return 0;
        if(idx < 0) return 1e9;
        if(dp[idx][walls] != -1) return dp[idx][walls];
        
        int pick = cost[idx] + f(idx-1, walls-1-time[idx], cost, time, dp);
        int npick = f(idx-1, walls, cost, time, dp);
        return dp[idx][walls] = min(pick, npick);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, cost, time, dp);
    }
};