class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < n; i++) {
            int temp = mx;
            mx = max({nums[i], mx*nums[i], mn*nums[i]});
            mn = min({nums[i], temp*nums[i], mn*nums[i]});
            ans = max(ans, mx);
        }
        return ans;
    }
};