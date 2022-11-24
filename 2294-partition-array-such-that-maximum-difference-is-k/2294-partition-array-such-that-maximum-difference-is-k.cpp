class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int base = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - base <= k) continue;
            else{
                ans++;
                base = nums[i];
            }
        }
        ans++;
        return ans;
    }
};