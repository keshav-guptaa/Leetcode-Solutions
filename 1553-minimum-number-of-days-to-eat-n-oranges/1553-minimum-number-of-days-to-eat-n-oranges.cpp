class Solution {
public:
    unordered_map<int, int> dp;
    
    int f(int n){
        if(n == 1 || n == 2) return n;
        if(dp.find(n) != dp.end()) return dp[n];
    
        int ans = INT_MAX;
        if(n % 2 == 0) ans = min(ans, 1 + f(n/2));
        if(n % 3 == 0) ans = min(ans, 1 + f(n/3));
        if((n-1) % 2 == 0 || (n-1) % 3 == 0) ans = min(ans, 1 + f(n-1));
        if((n-2) % 3 == 0) ans = min(ans, 2 + f(n-2));
        return dp[n] = ans;
    }
    
    int minDays(int n) {
        return f(n);
    }
};