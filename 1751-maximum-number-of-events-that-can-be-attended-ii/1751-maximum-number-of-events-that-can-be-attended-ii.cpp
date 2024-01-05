class Solution {
public:
    vector<int> start;
    int n;
    
    int f(int idx, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        if(idx == n || k == 0) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int npick = f(idx+1, k, events, dp);
        int pick = events[idx][2];
        int nidx = upper_bound(start.begin(), start.end(), events[idx][1]) - start.begin();
        pick += f(nidx, k-1, events, dp);
        return dp[idx][k] = max(pick, npick);
    }
    
    int maxValue(vector<vector<int>>& events, int l) {
        n = events.size();
        sort(events.begin(), events.end());
        for(auto &it: events) start.push_back(it[0]);
        //vector<vector<int>> dp(n, vector<int>(l+1, -1));
        vector<vector<int>> dp(n+5, vector<int>(l+5, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int k = 1; k <= l; k++){
                int npick = dp[idx+1][k];
                int pick = events[idx][2];
                int nidx = upper_bound(start.begin()+idx+1, start.end(), events[idx][1]) - start.begin();
                pick += dp[nidx][k-1];
                dp[idx][k] = max(pick, npick);
            }
        }
        //return f(0, l, events, dp);
        return dp[0][l];
    }
};