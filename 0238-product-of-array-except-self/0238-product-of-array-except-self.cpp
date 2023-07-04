class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, postfix = 1;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = n-1; i>= 0; i--){
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};