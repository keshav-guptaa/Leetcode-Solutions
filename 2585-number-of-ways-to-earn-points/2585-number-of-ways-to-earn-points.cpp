class Solution {
public:
    const int mod=1e9+7;
    long long dp[52][1050];
    
    long long f(int idx, int target, vector<vector<int>>& nums){
        if(idx >= nums.size()) return target == 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        long long ans = f(idx+1, target, nums);
        for(int i = 1; i <= nums[idx][0]; i++){
            if(target >= i*nums[idx][1]) ans += f(idx+1, target - i*nums[idx][1], nums);
            else break;
        }
        return dp[idx][target]= ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return f(0, target, types)%mod;
    }
};