class Solution {
public:
    int f(int idx, int id, vector<int>& p, vector<vector<int>>& dp){
        if(idx >= p.size()) return 0;
        if(dp[idx][id] != -1) return dp[idx][id];
        
        int score = id ? INT_MIN : INT_MAX;
        int sum = 0;
        if(id){
            for(int i = 0; i <= 2; i++){
                if(idx+i < p.size()) sum += p[idx+i];
                score = max(score, sum + f(idx+i+1, 1-id, p, dp));
            }
        }
        else{
            for(int i = 0; i <= 2; i++){
                if(idx+i < p.size()) sum += p[idx+i];
                score = min(score, -sum + f(idx+i+1, 1-id, p, dp));
            }
        }
        return dp[idx][id] = score;
    }
    
    string stoneGameIII(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int score = f(0, 1, p, dp);
        return score > 0 ? "Alice" : score == 0 ? "Tie" : "Bob";
    }
};