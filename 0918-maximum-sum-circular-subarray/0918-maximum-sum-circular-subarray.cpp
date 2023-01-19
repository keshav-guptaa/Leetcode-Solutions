class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX, s1 = 0, s2 = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i], s1 += nums[i], s2 += nums[i];
            mx = max(mx, s1);
            if(s1 < 0){
                s1 = 0;
            }
            mn = min(mn, s2);
            if(s2 > 0){
                s2 = 0;
            }
        }
        return (sum == s2)?mx:max(mx,sum-mn);
    }
};