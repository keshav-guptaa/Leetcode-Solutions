class Solution {
public:
    int dp[102][102][22], m, n, tot;
    
    int f(int idx, int neigh, int prevColor, vector<int>& houses, vector<vector<int>>& cost){
        if(idx == houses.size()){
            if(neigh == tot) return 0;
            return 1e7;
        }
        if(dp[idx][neigh][prevColor] != -1){
            return dp[idx][neigh][prevColor];
        } 
        int ans = 1e7;
        if(houses[idx]){
            int flag = (houses[idx] != prevColor);
            ans = min(ans, f(idx+1, neigh+flag, houses[idx], 
                           houses, cost));
        } 
        else{
            for(int i = 0; i < cost[idx].size(); i++){
                int newColor = i+1;
                int flag = (newColor != prevColor);
                ans = min(ans, cost[idx][i] + f(idx+1, neigh+flag,                                                 newColor, houses, cost));
            }
        }

        return dp[idx][neigh][prevColor] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int M, int N, int target) {
        m = M, n = N, tot = target;
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, 0, houses, cost);
        return ans != 1e7 ? ans : -1;
    }
};