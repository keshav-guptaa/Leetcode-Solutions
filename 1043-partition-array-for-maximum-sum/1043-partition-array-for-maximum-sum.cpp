class Solution {
public:
    int dp[505];
    
    int f(int idx, vector<int>& arr, int k){
        int n = arr.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int mx = INT_MIN, ans = INT_MIN;
        for(int j = idx; j < min(n,idx+k); j++){
            mx = max(mx, arr[j]);
            int sum = (j-idx+1)*mx + f(j+1, arr, k);
            ans = max(ans, sum);
        }
        return dp[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, arr, k);
    }
};