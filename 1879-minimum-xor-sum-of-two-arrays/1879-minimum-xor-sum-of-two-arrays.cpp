class Solution {
public:
    int dp[15][1 << 14], n;
    
    int f(int idx, int mask, vector<int>& n1, vector<int>& n2){
        if(idx >= n) return 0;
        if(dp[idx][mask] != -1) return dp[idx][mask];
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)) continue;
            int val = (n1[idx]^n2[i]) + f(idx+1, mask | (1 << i), n1, n2);
            ans = min(ans, val);
        }
        return dp[idx][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& n1, vector<int>& n2) {
        memset(dp, -1, sizeof dp);
        n = n1.size();
        return f(0, 0, n1, n2);
    }
};