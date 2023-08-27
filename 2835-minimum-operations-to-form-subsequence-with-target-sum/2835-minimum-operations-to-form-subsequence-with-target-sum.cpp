class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        int ans = 0;
        for(auto &it: nums) sum += it;
        if(sum < target) return -1;
        sort(nums.begin(), nums.end());
        while(target){
            int x = nums.back();
            nums.pop_back();
            if(sum-x >= target) sum -= x;
            else if(x <= target){
                sum -= x;
                target -= x;
            }
            else{
                nums.push_back(x/2);
                nums.push_back(x/2);
                ans++;
            }
        }
        return ans;
    }
};