class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), ct(n, 1);
        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        ct[i] = ct[j];
                    } 
                    else if(1 + dp[j] == dp[i]){
                        ct[i] += ct[j];
                    } 
                }
            }
            mx = max(mx, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx) ans += ct[i];
        }
        return ans;
    }
};