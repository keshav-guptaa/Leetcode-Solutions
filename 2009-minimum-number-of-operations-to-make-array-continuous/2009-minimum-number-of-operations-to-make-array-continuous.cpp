class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        int m = nums.size();
        int ans = 1e9;
        for(int i = 0; i < m; i++)
        {
            int j = upper_bound(nums.begin() + i, nums.end(), nums[i]+n-1) - nums.begin();  
            ans = min(ans,n-(j-i));
        }
        return ans;
    }
};