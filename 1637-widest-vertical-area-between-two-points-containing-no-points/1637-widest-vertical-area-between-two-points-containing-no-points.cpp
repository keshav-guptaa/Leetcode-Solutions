class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(auto &it: points){
            x.push_back(it[0]);
        }
        sort(x.begin(), x.end());
        int ans = 0;
        for(int i = 1; i < x.size(); i++) ans = max(x[i]-x[i-1], ans);
        return ans;
    }
};