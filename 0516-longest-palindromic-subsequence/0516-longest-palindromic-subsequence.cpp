class Solution {
public:
    int dp[1002][1002];
    
    int f(int idx1, int idx2, string &s, string &t){
        if(idx1 < 0 || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2]) return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, s, t);
        else return dp[idx1][idx2] = max(f(idx1-1, idx2, s, t), f(idx1, idx2-1, s, t));
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};