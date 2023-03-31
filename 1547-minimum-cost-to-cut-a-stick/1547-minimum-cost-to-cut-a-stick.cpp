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
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return f(1, cuts.size()-2, cuts);
    }
};