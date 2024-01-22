class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), a = 0, xorr = 0;
        vector<int> vis(n+5, 0);
        for(int i = 1; i <= n; i++){
            xorr ^= i^nums[i-1];
            if(vis[nums[i-1]]) a = nums[i-1];
            vis[nums[i-1]] = 1;
        }
        return {a, xorr^a};
    }
};