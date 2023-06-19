class Solution {
public:
    int f(int num, vector<int>& dp){
        if(num == 0) return 0;
        
        if(dp[num] != -1) return dp[num];
        
        for(int i = 1; i*i <= num; i++){
            if(!f(num-(i*i), dp)) return dp[num] = 1;
        }
        return dp[num] = 0;
    }
    
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};