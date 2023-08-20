class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int i = 0, j = 0, mx = 0, n = nums.size();
        while(j < n){
            m[nums[j]]++;
            mx = max(mx, m[nums[j]]);
            while(j-i+1-mx > k) --m[nums[i++]];
            j++;
        }
        return mx;
    }
};