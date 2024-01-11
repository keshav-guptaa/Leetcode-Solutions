class Solution {
public:
    int f(int idx, int prev, vector<int>& n1, vector<int>& n2, vector<vector<int>>& dp){
        if(idx == n1.size()) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        int ans = 0;
        
        if(prev == 2){
            ans = max(ans, f(idx+1, prev, n1, n2, dp));
            ans = max(ans, 1 + f(idx+1, 0, n1, n2, dp));
            ans = max(ans, 1 + f(idx+1, 1, n1, n2, dp));
        }
        else if(prev == 0){
            if(n1[idx] >= n1[idx-1]) ans = max(ans, 1 + f(idx+1, prev, n1, n2, dp));
            if(n2[idx] >= n1[idx-1]) ans = max(ans, 1 + f(idx+1, 1-prev, n1, n2, dp));
        }
        else{
            if(n1[idx] >= n2[idx-1]) ans = max(ans, 1 + f(idx+1, 1-prev, n1, n2, dp));
            if(n2[idx] >= n2[idx-1]) ans = max(ans, 1 + f(idx+1, prev, n1, n2, dp));
        }
        return dp[idx][prev] = ans;
    }
    
    int maxNonDecreasingLength(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        n1.insert(n1.begin(), 0);
        n2.insert(n2.begin(), 0);
        vector<vector<int>> dp(n+5, vector<int>(3, -1));
        return f(1, 2, n1, n2, dp);
    }
};