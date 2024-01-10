class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        vector<int> dp(n, 1);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(p[i][0] > p[j][1] && 1 + dp[j] > dp[i]) dp[i] = 1 + dp[j];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};