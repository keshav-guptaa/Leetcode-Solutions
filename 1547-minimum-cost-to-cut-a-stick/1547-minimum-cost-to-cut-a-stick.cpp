class Solution {
public:
    int dp[105][105];
    
    int f(int i, int j, vector<int> &cuts){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k <= j; k++){
            int temp = cuts[j+1] - cuts[i-1] + f(i, k-1, cuts) + f(k+1, j, cuts);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, 0, sizeof(dp));
        
        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                if(i > j) continue;
                int ans = INT_MAX;
                for(int k = i; k <= j; k++){
                    int temp = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[1][c];
    }
};