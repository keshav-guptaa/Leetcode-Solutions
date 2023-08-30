class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ops = 0;
        int mn = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= mn){
                mn = nums[i];
            }
            else{
                int tot = nums[i]/mn;
                if(nums[i] % mn != 0){
                    tot++;
                    mn = nums[i]/tot;
                }
                ops += tot-1;
            }
        }
        return ops;
    }
};