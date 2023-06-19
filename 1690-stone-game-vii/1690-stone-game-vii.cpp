class Solution {
public:
    int dp[1005][1005][2];
    
    int f(int s, int e, int id, int tot, vector<int>& p){
        if(s > e) return 0;
        if(dp[s][e][id] != -1) return dp[s][e][id];
        
        int score = id ? INT_MIN : INT_MAX;
        if(id){
            score = max(tot-p[s]+f(s+1, e, 1-id, tot-p[s], p), tot-p[e]+f(s, e-1, 1-id, tot-p[e], p));
        }
        else{
            score = min(-tot+p[s]+f(s+1, e, 1-id, tot-p[s], p), -tot+p[e]+f(s, e-1, 1-id, tot-p[e], p));
        }
        return dp[s][e][id] = score;
    }
    
    int stoneGameVII(vector<int>& p) {
        int e = p.size()-1;
        int tot = 0;
        for(int i = 0; i <= e; i++) tot += p[i];
        memset(dp, -1, sizeof dp);
        return f(0, e, 1, tot, p);
    }
};