class Solution {
public:
    vector<vector<int>> dp;
    int f(int n, int amt, vector<int>& coins){
        if(n == 0){
            if(amt % coins[0] == 0) return 1;
            else return 0;
        }
        if(amt == 0) return 1;
        if(dp[n][amt] != -1) return dp[n][amt];
        
        int npick = f(n-1, amt, coins);
        int pick = 0;
        if(coins[n] <= amt) pick = f(n, amt-coins[n], coins);
        return dp[n][amt] = pick + npick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins);
    }
};