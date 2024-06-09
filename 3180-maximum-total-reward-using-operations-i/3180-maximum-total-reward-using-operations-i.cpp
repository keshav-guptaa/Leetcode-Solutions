class Solution {
public:
    int dp[2005][4005], n;
    
    int f(int idx, int sum, vector<int>& reward){
        if(idx == n) return sum;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int ans = f(idx+1, sum, reward);
        if(reward[idx] > sum) ans = max(ans, f(idx+1, sum+reward[idx], reward));
        return dp[idx][sum] = ans;
    }
    
    int maxTotalReward(vector<int>& reward) {
        memset(dp, -1, sizeof dp);
        n = reward.size();
        sort(reward.begin(), reward.end());
        return f(0, 0, reward);
    }
};