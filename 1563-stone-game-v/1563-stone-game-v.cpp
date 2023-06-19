class Solution {
public:
    int f(int s, int e, int tot, vector<int>& p, vector<vector<int>>& dp){
        if(s == e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        
        int sum = 0, rem, score = 0;
        for(int i = s; i < e; i++){
            sum += p[i];
            rem = tot-sum;
            if(sum == rem)  score = max(score, sum + max(f(i+1, e, sum, p, dp), f(s, i, sum, p, dp)));
            else if(sum > rem) score = max(score, rem + f(i+1, e, rem, p, dp));
            else score = max(score, sum + f(s, i, sum, p, dp));
        }
        return dp[s][e] = score;
    }
    
    int stoneGameV(vector<int>& p) {
        int n = p.size();
        int tot = 0;
        for(int i = 0; i < n; i++) tot += p[i];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, tot, p, dp);
    }
};