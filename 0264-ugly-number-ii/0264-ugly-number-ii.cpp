class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for(int i = 1; i < n; i++){
            int twom = dp[p1]*2;
            int threem = dp[p2]*3;
            int fivem = dp[p3]*5;
            dp[i] = min({twom, threem, fivem});
            
            if(twom == dp[i]) p1++;
            if(threem == dp[i]) p2++;
            if(fivem == dp[i]) p3++;
        }
        return dp[n-1];
    }
};