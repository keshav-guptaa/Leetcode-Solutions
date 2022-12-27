class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0, tempidx = -1;
        while(j < n){
            sum += nums[j];
            if(sum == goal){
                int tempsum = sum;
                tempidx = i;
                while(tempsum == goal && tempidx <= j){
                    ans++;
                    tempsum -= nums[tempidx++];
                }
            }
            else if(sum > goal){
                while(sum > goal){
                    sum -= nums[i++];
                }
                int tempsum = sum;
                tempidx = i;
                while(tempsum == goal && tempidx <= j){
                    ans++;
                    tempsum -= nums[tempidx++];
                }
            }
            j++;
        }
        return ans;
    }
};