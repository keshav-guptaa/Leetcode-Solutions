class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int f(int idx, int prev, string& s, int k){
        if(idx == n) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        int pick = 0, npick = 0;
        if(prev == 26 || abs((s[idx]-'a')-prev) <= k) pick = 1 + f(idx+1, s[idx]-'a', s, k);
        npick = f(idx+1, prev, s, k);
        return dp[idx][prev] = max(pick, npick);
    }
    
    int longestIdealString(string s, int k) {
        n = s.length();
        dp.resize(n, vector<int>(27, -1));
        return f(0, 26, s, k);
    }
};