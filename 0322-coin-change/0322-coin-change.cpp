class Solution {
public:
    int memoization(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
        
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[ind];
            return 1e9;
        }
        
        //if(amount == 0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int notPick = memoization(ind-1, amount, coins, dp);
        int pick = 1e9;
        if(coins[ind] <= amount) pick = 1 + memoization(ind, amount - coins[ind], coins, dp);
        
        return dp[ind][amount] = min(pick, notPick);
    }
    
    int tabulation(int n, int k, vector<int>& coins, vector<vector<int>> &dp){
        for(int target = 0; target <= k; target++){
            if(target % coins[0] == 0) dp[0][target] = target / coins[0];
            else dp[0][target] = 1e9;
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int amount = 0; amount <= k; amount++){
                int notPick = dp[ind-1][amount];
                int pick = 1e9;
                if(coins[ind] <= amount) pick = 1 + dp[ind][amount - coins[ind]];
        
                dp[ind][amount] = min(pick, notPick);
            }
        }
        return dp[n-1][k];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = memoization(n-1, amount, coins, dp);
        //int ans = tabulation(n, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};