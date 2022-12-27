class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        while(j < n){
            if(nums[j] == 0) k--;
            
            if(k >= 0){
                ans = max(ans, j-i+1);
            }
            else if(k < 0){
                while(k < 0){
                    if(nums[i++] == 0) k++;
                }
            }
            j++;
        }
        return ans;
    }
};