class Solution {
public:
    int dp[302][12], n;
    
    int f(int idx, int d, vector<int>& j){
        if(idx == n || d == 0){
            if(idx == n && d == 0) return 0;
            else return 1e6;
        }
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int ans = INT_MAX, mx = -1;
        for(int i = idx; i < n; i++){
            mx = max(mx, j[i]);
            ans = min(ans, mx + f(i+1, d-1, j));
        }
        return dp[idx][d] = ans;
    }
    
    int minDifficulty(vector<int>& j, int d) {
        n = j.size();
        memset(dp, -1, sizeof dp);
        if(n < d) return -1;
        return f(0, d, j);
    }
};