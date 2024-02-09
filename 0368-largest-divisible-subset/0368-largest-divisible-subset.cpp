class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i]%nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
        int x = *max_element(dp.begin(), dp.end());
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(dp[i] == x){
                idx = i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(nums[idx]);
        while(hash[idx] != idx){
            idx = hash[idx];
            ans.push_back(nums[idx]);
        }
        return ans;
        
    }
};