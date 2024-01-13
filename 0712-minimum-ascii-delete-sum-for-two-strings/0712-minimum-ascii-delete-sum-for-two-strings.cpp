class Solution {
public:
    int dp[1005][1005];
    
    int f(int i1, int i2, string& s1, string& s2){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        int ans = 0;
        if(s1[i1] == s2[i2]) ans = 97 + (s1[i1]-'a') + f(i1-1, i2-1, s1, s2);
        else ans = max(f(i1-1, i2, s1, s2), f(i1, i2-1, s1, s2));
        return dp[i1][i2] = ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0, n = s1.length(), m = s2.length();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) ans += 97 + (s1[i]-'a');
        for(int i = 0; i < m; i++) ans += 97 + (s2[i]-'a');
        return ans - 2*f(n-1, m-1, s1, s2);
    }
};