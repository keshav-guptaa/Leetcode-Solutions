class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())){
                    dp[i] = 1;
                    break;
                } 
            }
        }
        return dp[n];
    }
};