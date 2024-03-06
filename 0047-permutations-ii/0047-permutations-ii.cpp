class Solution {
public:
    void func(vector<int>& nums, vector<int>& ds, set<vector<int>>& ans, int f[]){
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!f[i]){
                ds.push_back(nums[i]);
                f[i] = 1;
                func(nums, ds, ans, f);
                f[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        int f[nums.size()];
        for(int i = 0; i < nums.size(); i++){
            f[i] = 0;
        }
        func(nums, ds, ans, f);
        vector<vector<int>> ans2;
        for(auto &it: ans) ans2.push_back(it);
        return ans2;
    }
};