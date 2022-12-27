class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), ans = 0, count = 0;
        while(j < n){
            if(nums[j]&1) count++;
            
            if(count == k){
                int tempi = i;
                while(count == k){
                    ans++;
                    if(nums[tempi++]&1) break;
                }
            }
            else if(count > k){
                while(count > k){
                    if(nums[i]&1) count--;
                    i++;
                }
                int tempi = i;
                while(count == k){
                    ans++;
                    if(nums[tempi++]&1) break;
                }
            }
            j++;
        }
        return ans;
    }
};