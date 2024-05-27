class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ct = n;
        nums.insert(nums.begin(), -1);
        for(int i = 0; i < n+1; i++){
            if(ct > nums[i] && ct <= nums[i+1]) return ct;
            ct--;
        }
        return -1;
    }
};