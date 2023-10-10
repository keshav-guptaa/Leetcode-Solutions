class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,int n,vector<int>&v,int x)
    {   
        if(i >= n) return 0;
        if(j < 0) return 0;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i+1] - v[i] + solve(i+2,j,n,v,x);
        int b = v[j] - v[j-1] + solve(i,j-2,n,v,x);
        int c = x + solve(i+1,j-1,n,v,x);
        return dp[i][j] = min({a, b, c});
    }
    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) v.push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        int m = v.size();
        if(m%2 != 0) return -1;
        return solve(0,m-1,m,v,x);
    }
};