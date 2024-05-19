class Solution {
public:
    int dp[40][40][2];
    int f(long long curr, int jumps, int back, int flag, int k){
        if(curr > k+1) return 0;
        if(dp[jumps][back][flag] != -1) return dp[jumps][back][flag];
        
        int ways = 0;
        if(curr == k) ways++;
        if(!flag && curr != 0) ways += f(curr-1, jumps, back+1, 1, k);
        ways += f(curr+(1 << jumps), jumps+1, back, 0, k);
        return dp[jumps][back][flag] = ways;
    }
    
    int waysToReachStair(int k) {
        memset(dp, -1, sizeof dp);
        return f(1LL, 0, 0, 0, k);
    }
};