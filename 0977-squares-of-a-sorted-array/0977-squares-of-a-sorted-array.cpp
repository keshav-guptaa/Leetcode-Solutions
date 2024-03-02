class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        int idx = n-1;
        vector<int> ans(n);
        while(i <= j){
            if(nums[i]*nums[i] >= nums[j]*nums[j]){
                ans[idx] = nums[i]*nums[i];
                i++;
            }
            else{
                ans[idx] = nums[j]*nums[j];
                j--;
            }
            idx--;
        }
        return ans;
    }
};