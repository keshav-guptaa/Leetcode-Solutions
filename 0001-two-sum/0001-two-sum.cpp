class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int remaining = target - nums[i];
            if(m.find(remaining) != m.end() && m[remaining] != i){
                ans.push_back(m[remaining]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};