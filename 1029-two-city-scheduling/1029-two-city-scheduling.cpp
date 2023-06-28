class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<pair<int, int>> diff;
        for(int i = 0; i < n; i++){
            diff.push_back({costs[i][1] - costs[i][0], i});
        }
        sort(diff.begin(), diff.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2) ans += costs[diff[i].second][1];
            else ans += costs[diff[i].second][0];
        }
        return ans;
    }
};