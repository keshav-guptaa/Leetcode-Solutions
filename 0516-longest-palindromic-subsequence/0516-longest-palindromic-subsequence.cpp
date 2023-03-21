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
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return f(n-1, n-1, s, t);
    }
};