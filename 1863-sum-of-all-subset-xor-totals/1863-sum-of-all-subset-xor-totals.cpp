class Solution {
public:    
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int tot = (1 << n), ans = 0;
        
        for(int mask = 0; mask < tot; mask++){
            int curXor = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    curXor ^= nums[i];
                }
            }
            ans += curXor;
        }
        return ans;
    }
};