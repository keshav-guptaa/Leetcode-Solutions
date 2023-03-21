class Solution {
public:
    int dp[505][505];
    
    int f(int s, int e, vector<int>& p){
        if(s+1 == e) return max(p[s], p[e]);
        if(dp[s][e] != -1) return dp[s][e];
        
        int b = p[s] + max(f(s+2, e, p), f(s+1, e-1, p));
        int l = p[e] + max(f(s+1, e-1, p), f(s, e-2, p));
        
        return dp[s][e] = max(b, l);
    }
    
    bool stoneGame(vector<int>& p) {
        int s = 0, e = p.size()-1;
        memset(dp, -1, sizeof(dp));
        int a = f(s, e, p);
        int sum = 0;
        for(int i = 0; i <= e; i++) sum += p[i];
        return a > sum - a;
    }
};