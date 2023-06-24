class Solution {
public:
    const int mod = 1e9+7;
    vector<int> dp;
    int f(int idx, string& s){
        if(idx == s.length()) return 1;
        if(s[idx] == '0' || idx > s.length()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        long long ways = 0;
        if(s[idx] == '*') ways += 9LL*f(idx+1, s);
        else ways += 1LL*f(idx+1, s);
        
        if(idx + 1 < s.length()){
            if(s[idx] == '*'){
                if(s[idx+1] == '*') ways += 15LL*f(idx+2, s);
                else if(s[idx+1] <= '6') ways += 2LL*f(idx+2, s);
                else if(s[idx+1] > '6') ways += 1LL*f(idx+2, s);
            }
            else if(s[idx] == '1'){
                if(s[idx+1] == '*') ways += 9LL*f(idx+2, s);
                else ways += 1LL*f(idx+2, s);
            }
            else if(s[idx] == '2'){
                if(s[idx+1] == '*') ways += 6LL*f(idx+2, s);
                else if(s[idx+1] <= '6') ways += 1LL*f(idx+2, s);
            }
        }
        return dp[idx] = ways%mod;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n, -1);
        return f(0, s)%mod;
    }
};