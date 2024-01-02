class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> m;
        int mx = 0;
        for(auto it: nums){
            m[it]++;
            mx = max(mx, m[it]);
        }
        vector<vector<int>> ans;
        
        for(int i = 0; i < mx; i++){
            vector<int> v;
            for(auto &it: m){
                if(it.second != 0){
                    v.push_back(it.first);
                    it.second--;
                }
            }
            ans.push_back(v);
            //v.clear();
        }
        
        return ans;
    }
};