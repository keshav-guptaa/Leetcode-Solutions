class Solution {
public:
    int dp[505][505][2];
    
    int f(int s, int e, int id, vector<int>& p){
        if(s > e) return 0;
        if(dp[s][e][id] != -1) return dp[s][e][id];
        
        int ans = 0;
        if(id) ans = max(p[s]+f(s+1, e, 1-id, p), p[e]+f(s, e-1, 1-id, p));
        else ans = min(-p[s]+f(s+1, e, 1-id, p), -p[e]+f(s, e-1, 1-id, p));
        return dp[s][e][id] = ans;
    }
    
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        memset(dp, -1, sizeof dp);
        return f(0, n-1, 1, p);
    }
};