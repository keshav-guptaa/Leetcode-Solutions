class Solution {
public:
    int memoization(int ind, int prev_ind, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int take = 0, notTake = 0;
        
        notTake = memoization(ind+1, prev_ind, nums, dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1 + memoization(ind+1, ind, nums, dp);
        }
        
        return dp[ind][prev_ind+1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
                int take = 0, notTake = 0;
        
                notTake = dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    take = 1 + dp[ind+1][ind+1];
                }
        
                dp[ind][prev_ind+1] = max(take, notTake);
            }
        }
        return dp[0][0];
        //return memoization(0, -1, nums, dp);
    }
};