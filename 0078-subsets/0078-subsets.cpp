class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int subsets = (1<<size);
        vector<vector<int>> ans;
        for(int subsetMask = 0; subsetMask < subsets; subsetMask++){
            vector<int> m;
            for(int i = 0; i < size; i++){
                if((subsetMask & (1 << i)) != 0){
                    m.push_back(nums[i]);
                }
            }
            ans.push_back(m);
        }
        return ans;
    }
};