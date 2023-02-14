class Solution {
public:
    int dp[32][1011];
    const int m = 1e9+7;
    
    int f(int n, int t, int k){
        if(t == 0 && n == 0) return 1;
        if(t <= 0 || n <= 0) return 0;
        if(dp[n][t] != -1) return dp[n][t];
        
        int ans = 0;
        for(int x = 1; x <= k; x++){
            ans = (ans%m + f(n-1, t-x, k)%m)%m;
        }
        return dp[n][t] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return f(n, target, k);
    }
};