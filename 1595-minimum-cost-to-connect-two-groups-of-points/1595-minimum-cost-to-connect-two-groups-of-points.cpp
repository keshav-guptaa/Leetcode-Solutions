class Solution {
public:
    int n, m;
    vector<int> cheap;
    int dp[13][1 << 12];
    
    int f(int idx, int mask, vector<vector<int>>& cost){
        if(idx == n){
            int cost = 0;
            for(int j = 0; j < m; j++){
                if(!(mask & (1 << j))) cost += cheap[j];
            }
            return cost;
        }
        if(dp[idx][mask] != -1) return dp[idx][mask];
        
        int ans = 1e9;
        for(int j = 0; j < m; j++){
            ans = min(ans, cost[idx][j] + f(idx+1, mask | (1 << j), cost));
        }
        return dp[idx][mask] = ans;
    }
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp, -1, sizeof dp);
        n = cost.size(), m = cost[0].size();  
        cheap.resize(m, 101);
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                cheap[j] = min(cheap[j], cost[i][j]);
            }
        }
        return f(0, 0, cost);
    }
};