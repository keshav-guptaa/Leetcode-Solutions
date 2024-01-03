class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        vector<int> dp;
        sort(e.begin(), e.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        for(int i = 0; i < n; i++){
            int idx = lower_bound(dp.begin(), dp.end(), e[i][1]) - dp.begin();
            if(idx >= dp.size()) dp.push_back(e[i][1]);
            else dp[idx] = e[i][1];
            
        }
        return dp.size();
    }
};