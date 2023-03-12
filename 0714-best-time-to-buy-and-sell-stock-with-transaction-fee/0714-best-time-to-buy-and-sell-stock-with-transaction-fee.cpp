class Solution {
public:
    int f(int idx, int buy, vector<int>& p, vector<vector<int>>& dp, int fee){
        if(idx >= p.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-p[idx]+f(idx+1, 0, p, dp, fee), f(idx+1, 1, p, dp, fee));
        }
        else{
            profit = max(p[idx]-fee+f(idx+1, 1, p, dp, fee), f(idx+1, 0, p, dp, fee));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>> dp(p.size()+1, vector<int>(2, -1));
        return f(0, 1, p, dp, fee);
    }
};