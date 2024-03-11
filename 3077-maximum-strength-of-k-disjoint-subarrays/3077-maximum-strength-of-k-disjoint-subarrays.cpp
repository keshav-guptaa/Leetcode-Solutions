class Solution {
public:
    long long f(int flag, int k, int idx, vector<vector<vector<long long>>>& dp, vector<int>& nums){
        if(k == 0) return 0;
        if(idx == nums.size()){
            if(k == 1 && flag == 1) return 0;
            return -1e15;
        }
        if(dp[flag][k][idx] != -1e16) return dp[flag][k][idx];
        
        long long ans = (k&1 ? k : -k)*1LL*nums[idx] + f(1, k, idx+1, dp, nums);
        if(flag) ans = max(ans, f(0, k-1, idx, dp, nums));
        else ans = max(ans, f(0, k, idx+1, dp, nums));
        
        return dp[flag][k][idx] = ans;
    }
    
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>> (k + 1, vector<long long> (n, -1e16)));
        return f(0, k, 0, dp, nums);
    }
};