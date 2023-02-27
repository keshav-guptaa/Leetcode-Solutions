class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, cnt = 0, end = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(m.find(sum-target) != m.end() && m[sum-target] >= end){
                cnt++;
                end = i;
            }
            m[sum] = i;
        }
        return cnt;
    }
};