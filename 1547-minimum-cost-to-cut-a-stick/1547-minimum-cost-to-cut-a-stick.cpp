class Solution {
public:
    int dp[105][105];
    
    int f(int i, int j, vector<int> &cuts){
        if(i >= j-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            int temp = cuts[j] - cuts[i] + f(i, k, cuts) + f(k, j, cuts);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return f(0, cuts.size()-1, cuts);
    }
};