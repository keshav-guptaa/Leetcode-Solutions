class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int ans = -1;
        int temp;
        while(i < j){
            temp = nums[i++] + nums[j--];
            ans = max(ans, temp);
        }
        return ans;
    }
};