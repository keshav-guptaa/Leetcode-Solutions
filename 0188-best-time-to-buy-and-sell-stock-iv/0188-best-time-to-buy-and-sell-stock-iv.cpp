class Solution {
public:
    int f(int idx, int buy, int cap, vector<int>& p, vector<vector<vector<int>>>& dp){
        if(idx == p.size()) return 0;
        if(cap == 0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-p[idx] + f(idx+1, 0, cap, p, dp), f(idx+1, 1, cap, p, dp));
        }
        else{
            profit = max(p[idx] + f(idx+1, 1, cap-1, p, dp), f(idx+1, 0, cap, p, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, p, dp);
    }
};