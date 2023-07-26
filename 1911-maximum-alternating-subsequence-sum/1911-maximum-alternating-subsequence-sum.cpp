class Solution {
public:
    long long dp[100005][2];
    
    long long f(int idx, int fl, vector<int>& nums){
        if(idx >= nums.size()) return 0;
        if(dp[idx][fl] != -1) return dp[idx][fl];
        
        long long npick = f(idx+1, fl, nums), pick = f(idx+1, 1-fl, nums); 
        if(fl) pick -= nums[idx];
        else pick += nums[idx];
        return dp[idx][fl] = max(pick, npick);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        return f(0, 0, nums);
    }
};