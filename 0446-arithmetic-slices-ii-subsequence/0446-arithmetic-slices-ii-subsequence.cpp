class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long long diff = nums[i] + 0LL -nums[j];
                int ct = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += ct + 1;
                ans += ct;
            }
        }
        return ans;
    }
};