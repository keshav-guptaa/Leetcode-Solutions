class Solution {
public:
    const int mod = 1e9+7;
    
    int f(int city, int fuel, int finish, vector<int>& l, vector<vector<int>>& dp){
        if(fuel < 0) return 0;
        if(dp[city][fuel] != -1) return dp[city][fuel];
        
        long long ways = city == finish ? 1: 0;
        for(int i = 0; i < l.size(); i++){
            if(i != city){
                ways += f(i, fuel-abs(l[i]-l[city]), finish, l, dp);
                ways %= mod;
            }
        }
        return dp[city][fuel] = ways;
    }
    
    int countRoutes(vector<int>& l, int start, int finish, int fuel) {
        int n = l.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        return f(start, fuel, finish, l, dp);
    }
};