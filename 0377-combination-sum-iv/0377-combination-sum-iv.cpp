class Solution {
public:
    int dp[1005];
    
    int f(int tot, vector<int>& nums){
        if(tot == 0) return 1;
        if(tot < 0) return 0;
        if(dp[tot] != -1) return dp[tot];
        
        int ans = 0;
        for(auto it: nums){
            ans += f(tot-it, nums);
        }
        return dp[tot] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return f(target, nums);
    }
};