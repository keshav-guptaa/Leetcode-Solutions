class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int ans = 0, n = nums.size(), j = 0, i = 0;
        map<int, int> m;
        while(i < n){
            m[nums[i]]++;
            if(m[nums[i]] == 1) k--;
            while(k < 0){
                m[nums[j]]--;
                if(m[nums[j]] == 0) k++;
                j++;
            }
            ans += (i-j+1);
            i++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};