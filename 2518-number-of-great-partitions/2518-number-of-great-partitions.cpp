#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    
    ll f(int idx, ll sum, int k, vector<int>& nums, vector<vector<int>>& dp){
        if(sum > k) return 0;
        if(idx == nums.size()) return sum < k ? 1 : 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        ll pick = f(idx+1, sum+nums[idx], k, nums, dp) % mod;
        ll npick = f(idx+1, sum, k, nums, dp) % mod;
        return dp[idx][sum] = pick + npick;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        ll tot = 0;
        for(auto &it: nums) tot += it;
        if(tot < 2*k) return 0;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        ll x = f(0, 0, k, nums, dp), y = 2;
        for(int i = 2; i <= n; i++){
            y *= 2;
            y %= mod;
        }
        y -= 2, x--;
        ll ans = ((y - ((2*x)%mod)) + mod)%mod;
        return ans;
    }
};