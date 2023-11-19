class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        s.insert(nums[0]);
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            ans += s.size();
            if(nums[i] == *prev(s.end())) ans--;
            s.insert(nums[i]);
        }
        return ans;
    }
};