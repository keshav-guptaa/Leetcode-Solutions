class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n <= 3) return 0;
        int x = n-4;
        long long ans = 1e12;
        for(int i = 0; i + x < n; i++){
            ans = min(ans, 0LL+nums[i+x]-nums[i]);
        }
        return int(ans);
    }
};