class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0, ct = 0, diff = nums[1]-nums[0];
        for(int i = 1; i < n-1; i++){
            if(nums[i+1] - nums[i] != diff){
                diff = nums[i+1] - nums[i];
                ct = 0;
            }
            else ct++;
            ans += ct;
        }
        return ans;
    }
};