class Solution {
public:
    int dp[1005];
    const int mod = 1e9+7;
    
    int f(int day, int n, int delay, int forget){
        if(dp[day] != -1) return dp[day];
        long long people = 0;
        if(day + forget > n) people++;
        for(int st = day + delay; st < min(n+1, day + forget); st++){
            people += f(st, n, delay, forget);
            people %= mod;
        }
        return dp[day] = people;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp, -1, sizeof dp);
        return f(1, n, delay, forget);
    }
};