class Solution {
public:
    int dp[5005][4][4][4];
    const int mod = 1e9+7;
    
    int f(int idx, int a1, int b1, int c1){
        if(idx == 0) return 1;
        if(dp[idx][a1][b1][c1] != -1) return dp[idx][a1][b1][c1];
        
        long long ways = 0;
        for(int a = 1; a <= 3; a++){
            if(a == a1) continue;
            for(int b = 1; b <= 3; b++){
                if(b == a || b == b1) continue;
                for(int c = 1; c <= 3; c++){
                    if(c == b || c == c1) continue;
                    ways += f(idx-1, a, b, c);
                    ways %= mod;
                }
            }
        }
        return dp[idx][a1][b1][c1] = ways;
    }
    
    int numOfWays(int n) {
        memset(dp, -1, sizeof dp);
        return f(n, 0, 0, 0);
    }
};