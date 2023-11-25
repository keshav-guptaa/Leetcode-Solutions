class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int sum = accumulate(nums.begin(), nums.end(), 0), pf = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            int val = sum - nums[i]*n + 2*(i*nums[i] - pf);
            ans.push_back(val);
            pf += nums[i];
        }
        return ans;
    }
};