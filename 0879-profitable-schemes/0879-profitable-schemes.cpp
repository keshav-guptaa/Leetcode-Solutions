class Solution {
public:
    //states => idx, number of people, min profit needed
    long long dp[105][105][105];
    const int mod = 1e9+7;
    int m;
    
    long long f(int idx, int n, int need, vector<int>& g, vector<int>& p){
        if(n < 0) return 0;
        if(idx == m) return need <= 0;
        if(need < 0) need = 0;
        if(dp[idx][n][need] != -1) return dp[idx][n][need];
        
        long long npick = f(idx+1, n, need, g, p);
        long long pick = f(idx+1, n-g[idx], need-p[idx], g, p);
        return dp[idx][n][need] = (pick + npick)%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m = group.size();
        memset(dp, -1, sizeof dp);
        return f(0, n, minProfit, group, profit);
    }
};