class Solution {
public:
    int dp[505];
    
    int f(int idx, vector<int>& arr, int k){
        int n = arr.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int mx = INT_MIN, ans = INT_MIN, len = 0;
        for(int j = idx; j < min(n,idx+k); j++){
            len++;
            mx = max(mx, arr[j]);
            int sum = len*mx + f(j+1, arr, k);
            ans = max(ans, sum);
        }
        return dp[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, arr, k);
    }
};