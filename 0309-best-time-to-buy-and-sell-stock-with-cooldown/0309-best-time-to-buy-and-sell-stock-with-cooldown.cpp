class Solution {
public:
    int memoization(vector<int>& prices, int ind, int buy, int n, vector<vector<int>> &dp){
        int profit;
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy){
            profit = max(-prices[ind] + memoization(prices, ind+1, 0, n, dp), memoization(prices, ind+1, 1, n, dp));
        }
        else{
            profit = max(prices[ind] + memoization(prices, ind+2, 1, n, dp), memoization(prices, ind+1, 0, n, dp));
        }
        return dp[ind][buy] = profit;
    }
    
    int tabulation(vector<int>& prices, int n, vector<vector<int>> &dp){
        int profit;
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                 if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                 }
                 else{
                    profit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                 }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int> (2, 0));
        // return memoization(prices, 0, 1, prices.size(), dp);
         return tabulation(prices, prices.size(), dp);
    }
};