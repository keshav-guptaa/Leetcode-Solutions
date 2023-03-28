class Solution {
public:
    vector<int> dp;
    
    int f(int idx, vector<int>& days, vector<int>& costs){
        if(idx >= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int i1 = lower_bound(days.begin(), days.end(), days[idx]+1) - days.begin();
        int i2 = lower_bound(days.begin(), days.end(), days[idx]+7) - days.begin();
        int i3 = lower_bound(days.begin(), days.end(), days[idx]+30) - days.begin();
        
        int c1 = costs[0] + f(i1, days, costs);
        int c2 = costs[1] + f(i2, days, costs);
        int c3 = costs[2] + f(i3, days, costs);
        
        return dp[idx] = min({c1, c2, c3});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n+1, -1);
        return f(0, days, costs);
    }
};