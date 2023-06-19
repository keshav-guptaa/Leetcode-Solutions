class Solution {
public:
    int dp[50005][2];
    
    int f(int idx, int id, vector<int>& p){
        if(idx >= p.size()) return 0;
        if(dp[idx][id] != -1) return dp[idx][id];
        
        int score = id ? INT_MIN : INT_MAX;
        int sum = 0;
        if(id){
            for(int i = 0; i <= 2; i++){
                if(idx+i < p.size()) sum += p[idx+i];
                score = max(score, sum + f(idx+i+1, 1-id, p));
            }
        }
        else{
            for(int i = 0; i <= 2; i++){
                if(idx+i < p.size()) sum += p[idx+i];
                score = min(score, -sum + f(idx+i+1, 1-id, p));
            }
        }
        return dp[idx][id] = score;
    }
    
    string stoneGameIII(vector<int>& p) {
        int n = p.size();
        //vector<vector<int>> dp(n, vector<int>(2, -1));
        //memset(dp, -1, sizeof dp);
        memset(dp, 0, sizeof dp);
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int id = 0; id <= 1; id++){
                int score = id ? INT_MIN : INT_MAX;
                int sum = 0;
                if(id){
                    for(int i = 0; i <= 2; i++){
                        if(idx+i < p.size()) sum += p[idx+i];
                        score = max(score, sum + dp[idx+i+1][1-id]);
                    }
                }
                else{
                    for(int i = 0; i <= 2; i++){
                        if(idx+i < p.size()) sum += p[idx+i];
                        score = min(score, -sum + dp[idx+i+1][1-id]);
                    }
                }
                dp[idx][id] = score;
            }
        }
        
        
        int score = dp[0][1];
        if (score > 0) return "Alice";
        if (score < 0) return "Bob";
        return "Tie";
    }
};