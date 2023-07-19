class Solution {
public:
    vector<long long> dp;
    
    long long f(int idx, vector<vector<int>>& q){
        if(idx >= q.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        long long pick = 0, npick = 0;
        pick = q[idx][0] + f(idx + q[idx][1] + 1, q);
        npick = f(idx+1, q);
        return dp[idx] = max(pick, npick);
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        dp.resize(n, -1);
        return f(0, q);
        /*
        long long ans = -1;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
        */
    }
};