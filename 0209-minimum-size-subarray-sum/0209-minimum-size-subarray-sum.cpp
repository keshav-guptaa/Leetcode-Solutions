class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, len = INT_MAX, sum = 0, n = nums.size();
        while(j < n){
            sum += nums[j];
            //if(sum == target) len = min(len, j-i+1);
            if(sum >= target){
                while(sum >= target){
                    len = min(len, j-i+1);
                    sum -= nums[i++];
                }
            }
            j++;
        }
        return (len != INT_MAX) ? len : 0;
    }
};