class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prev;
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                 prev = nums[i];
                 nums[i] = nums[i-1] + 1;
                 ans = ans + nums[i] - prev;
            }
        }
        return ans;
    }
};