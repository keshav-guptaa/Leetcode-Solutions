class Solution {
public:
    vector<int> dp;
    int f(string s, int idx){
        if(idx == s.length()) return 1;
        if(dp[idx] != -1) return dp[idx];
        int ways = 0;
        if(s[idx] != '0') ways += f(s, idx+1);
        if(idx+1 < s.length() && (s[idx] == '1' || (s[idx] == '2' &&
           s[idx+1] <= '6'))){
            ways += f(s, idx+2);
        }
        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n, -1);
        return f(s, 0);
    }
};