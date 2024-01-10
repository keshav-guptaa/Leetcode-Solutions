class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                dp[i] = max(dp[i], p[i][0] > p[j][1] ? dp[j] + 1 : dp[j]);
            }
        }
        return dp[n-1];
    }
};