class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int idx, int time, vector<int>& s){
        if(idx == s.size()) return 0;
        if(dp[idx][time] != -1) return dp[idx][time];
        
        int pick = time*s[idx] + f(idx+1, time+1, s);
        int npick = f(idx+1, time, s);
        return dp[idx][time] = max(pick, npick);
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        dp.resize(n, vector<int>(n+1, -1));
        return f(0, 1, s);
        
    }
};