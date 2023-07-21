class Solution {
public:
    //index, absent, late
    int dp[100005][3][4];
    const int mod = 1e9+7;
    
    int f(int idx, int a, int l, int n){
        if(a == 2 || l == 3) return 0;
        if(idx == n) return 1;
        if(dp[idx][a][l] != -1) return dp[idx][a][l];
        
        long long ways = 0;
        //present
        ways += f(idx+1, a, 0, n);
        //absent
        ways += f(idx+1, a+1, 0, n);
        //late
        ways += f(idx+1, a, l+1, n);
        ways %= mod;
        return dp[idx][a][l] = ways;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, 0, n);
    }
};