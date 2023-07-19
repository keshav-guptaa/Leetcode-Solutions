class Solution {
public:
    int f(int mask, int ops, vector<int>& nums, unordered_map<int, int>& dp){
        int n = nums.size()/2, m = n*2;
        if(ops > n) return 0;
        if(dp.find(mask) != dp.end()) return dp[mask];
        
        for(int i = 0; i < m; i++){
            if((mask & (1 << i))) continue;
            for(int j = i+1; j < m; j++){
                if(mask & (1 << j)) continue;
                int newMask = (1 << i) | (1 << j) | mask;
                int score = ops*__gcd(nums[i], nums[j]) + f(newMask, ops+1, nums, dp);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }
    
    int maxScore(vector<int>& nums) {
        unordered_map<int, int> dp;
        return f(0, 1, nums, dp);
    }
};