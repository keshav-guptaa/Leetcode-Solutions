class Solution {
public:
    int f(int num, vector<int>& dp){
        if(num == 0) return 0;
        if(dp[num] != -1) return dp[num];
        
        int mn = 1e9;
        for(int i = 1; i*i <= num; i++){
            mn = min(mn, 1 + f(num-i*i, dp));
        }
        return dp[num] = mn;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};