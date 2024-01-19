class Solution {
public:
    int dp[105][105][2];
    
    int f(int idx, int m, int id, vector<int>& p){
        if(idx >= p.size()) return 0;
        if(dp[idx][m][id] != -1) return dp[idx][m][id];
        
        int score = id ? INT_MIN : INT_MAX;
        int sum = 0;
        for(int i = idx; i < p.size() && i < idx + 2*m; i++){
            sum += p[i];
            int next = f(i+1, max(m, i-idx+1), 1-id, p);
            if(id) score = max(score, sum + next);
            else score = min(score, next);
        }
        return dp[idx][m][id] = score;
    }
    
    int stoneGameII(vector<int>& p) {
        memset(dp, -1, sizeof dp);
        return f(0, 1, 1, p);
        
    }
};