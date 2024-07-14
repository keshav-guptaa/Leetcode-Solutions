class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> vp;
        for(auto& it: logs){
            vp.push_back({it[0], 1});
            vp.push_back({it[1], -1});
        }
        sort(vp.begin(), vp.end());
        int ct = 0, mx = 0, ans;
        for(int i = 0; i < vp.size(); i++){
            if(vp[i].second == 1) ct++;
            else ct--;
            if(ct > mx){
                mx = ct;
                ans = vp[i].first;
            }
        }
        return ans;
    }
};