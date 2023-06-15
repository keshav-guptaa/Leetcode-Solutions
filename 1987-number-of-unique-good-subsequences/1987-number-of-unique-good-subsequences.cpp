class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.length();
        int mod = 1e9+7;
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        int zero = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                zero = 1;
                dp[0][i] = (1LL*dp[0][i+1] + 1LL + 1LL*dp[1][i+1])%mod;
                dp[1][i] = dp[1][i+1]%mod;
            }
            else{
                dp[1][i] = (1LL*dp[0][i+1] + 1LL + 1LL*dp[1][i+1])%mod;
                dp[0][i] = dp[0][i+1]%mod;
            }
        }
        return (dp[1][0] + 0LL + zero) % mod;
    }
};