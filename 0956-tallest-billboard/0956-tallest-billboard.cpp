class Solution {
public:
    vector<unordered_map<int, int>> dp;
    
    int f(int idx, int sum, vector<int>& rods){
        if(idx < 0){
            if(sum == 0) return 0;
            return INT_MIN;
        }
        if(dp[idx].find(sum) != dp[idx].end()) return dp[idx][sum];
        
        int nn = f(idx-1, sum, rods);
        int pn = rods[idx] + f(idx-1, sum+rods[idx], rods);
        int np = f(idx-1, sum-rods[idx], rods);
        return dp[idx][sum] = max({nn, pn, np});
    }
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        dp.resize(n);
        return f(n-1, 0, rods);
    }
};