class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        while(j < n){
            if(nums[j] == mx) k--;
            while(i <= j && k == 0){
                ans += n-j;
                if(nums[i++] == mx) k++;
            }
            j++;
        }
        return ans;
    }
};