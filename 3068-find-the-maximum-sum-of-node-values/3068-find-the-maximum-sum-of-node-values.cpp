class Solution {
public:
    long long dp[2][20005];
    int n;
    
    long long f(int flag, int idx, int k, vector<int>& nums){
        if(idx == n){
            if(flag) return 0;
            else return -1e18;
        }
        if(dp[flag][idx] != -1) return dp[flag][idx];
        
        long long xorr = (nums[idx]^k) + f(1-flag, idx+1, k, nums);
        long long notxorr = nums[idx] + f(flag, idx+1, k, nums);
        return dp[flag][idx] = max(xorr, notxorr);
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return f(1, 0, k, nums);
    }
};