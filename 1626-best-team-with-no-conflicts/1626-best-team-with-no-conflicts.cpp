class Solution {
public:
    int f(int idx, int prev, vector<pair<int, int>>& v, vector<vector<int>>& dp){
        if(idx >= v.size()) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int npick = f(idx+1, prev, v, dp);
        int pick = 0;
        if(prev == -1 || v[idx].second >= v[prev].second){
            pick = v[idx].second + f(idx+1, idx, v, dp);
        } 
        return dp[idx][prev+1] = max(pick, npick);
    }
    
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int n = s.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({a[i], s[i]});
        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, -1, v, dp);
    }
};