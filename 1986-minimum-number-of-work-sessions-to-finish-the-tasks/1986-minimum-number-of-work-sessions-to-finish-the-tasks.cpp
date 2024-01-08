class Solution {
public:
    int tot, n;
    int dp[16][1<<14];
    
    int f(int curr, int mask, vector<int>& tasks){
        if(mask == (1 << n) - 1) return 0;
        if(dp[curr][mask] != -1) return dp[curr][mask];
        
        int ans = n;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))){
                int nmask = mask | (1 << i);
                if(curr + tasks[i] <= tot){
                    ans = min(ans, f(curr+tasks[i], nmask, tasks));
                }
                else ans = min(ans, 1 + f(tasks[i], nmask, tasks));
            }
        }
        return dp[curr][mask] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size(), tot = sessionTime;
        memset(dp, -1, sizeof dp);
        return 1 + f(0, 0, tasks);
    }
};