class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) ct++;
        }
        if(ct&1) return -1;
        return 1;
    }
};