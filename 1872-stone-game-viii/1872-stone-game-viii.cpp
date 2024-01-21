class Solution {
public:
    int dp[100005][2], n;
    
    int f(int idx, int id, vector<int>& s){
        if(idx == n-1) return id ? s[idx] : -s[idx];
        if(dp[idx][id] != -1) return dp[idx][id];
        
        int score = id ? INT_MIN : INT_MAX;
        if(id) score = max(f(idx+1, 1-id, s) + s[idx], f(idx+1, id, s));
        else score = min(f(idx+1, 1-id, s) - s[idx], f(idx+1, id, s));
        return dp[idx][id] = score;
    }
    
    int stoneGameVIII(vector<int>& s) {
        n = s.size();
        for(int i = 1; i < n; i++) s[i] += s[i-1];
        memset(dp, -1, sizeof dp);
        return f(1, 1, s);
    }
};