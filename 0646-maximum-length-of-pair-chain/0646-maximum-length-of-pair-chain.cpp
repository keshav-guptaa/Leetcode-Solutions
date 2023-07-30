class Solution {
public:
    vector<int> dp;
    
    int f(int idx, vector<vector<int>>& p, int cmp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int pick = 0;
        if(p[idx][1] < cmp){
            pick = 1 + f(idx-1, p, p[idx][0]);
        }
        int npick = f(idx-1, p, cmp);
        
        return dp[idx] = max(pick, npick);
    }
    
    int findLongestChain(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        dp.resize(n, -1);
        return f(n-1, p, 1001);
    }
};