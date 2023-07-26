class Solution {
public:
    int f(int idx, vector<int>& dp, vector<vector<int>>& v, vector<int>& s){
        if(idx >= s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int npick = f(idx+1, dp, v, s);
        int nidx = lower_bound(s.begin(), s.end(), v[idx][1]) - s.begin();
        int pick = v[idx][2] + f(nidx, dp, v, s); 
        return dp[idx] = max(pick, npick);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({s[i], e[i], p[i]});
        }
        vector<int> dp(n, -1);
        sort(v.begin(), v.end());
        sort(s.begin(), s.end());
        return f(0, dp, v, s);
    }
};