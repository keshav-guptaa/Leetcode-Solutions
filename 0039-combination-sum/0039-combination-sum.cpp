class Solution {
public:
    void find(int idx, vector<int>& candidates, int target, vector<int> &ds,
              vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(idx == candidates.size()) return;
        
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            find(idx, candidates, target-candidates[idx], ds, ans);
            ds.pop_back();
        }
        find(idx+1, candidates, target, ds, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(0, candidates, target, ds, ans);
        return ans;
    }
};