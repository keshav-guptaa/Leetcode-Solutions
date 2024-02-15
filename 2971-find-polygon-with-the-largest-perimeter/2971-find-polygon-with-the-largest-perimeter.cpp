class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = nums[0], ans = -1;
        for(int i = 1; i < n-1; i++){
            sum += nums[i];
            if(sum > nums[i+1]) ans = max(ans, sum + nums[i+1]);
        }
        return ans;
    }
};