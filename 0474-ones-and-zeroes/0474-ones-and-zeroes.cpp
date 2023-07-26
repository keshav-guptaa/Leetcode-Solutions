class Solution {
public:
    int dp[605][105][105];
    
    int f(int idx, int m, int n, vector<pair<int, int>>& v){
        if(idx >= v.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        int npick = f(idx+1, m, n, v), pick = 0;
        int zeros = v[idx].first, ones = v[idx].second;
        if(zeros <= m && ones <= n) pick = 1 + f(idx+1, m-zeros, n-ones, v);
        return dp[idx][m][n] = max(pick, npick);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x = strs.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < x; i++){
            int sz = strs[i].length();
            int zeros = 0, ones = 0;
            for(int j = 0; j < sz; j++){
                if(strs[i][j] == '0') zeros++;
                else ones++;
            }
            v.push_back({zeros, ones});
        }
        memset(dp, -1, sizeof dp);
        return f(0, m, n, v);
    }
};