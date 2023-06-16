class Solution {
public:
    
    int f(int s, int e, vector<int>& p, vector<vector<int>>& dp){
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        
        int b = p[s] + min(f(s+2, e, p, dp), f(s+1, e-1, p, dp));
        int l = p[e] + min(f(s+1, e-1, p, dp), f(s, e-2, p, dp));
        
        return dp[s][e] = max(b, l);
    }
    
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int a = f(0, n-1, p, dp);
        int sum = 0;
        for(int i = 0; i < n; i++) sum += p[i];
        return a > sum - a;
    }
};