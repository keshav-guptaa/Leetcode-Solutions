const int N = 201;
int dp[N][N];
int changes[N][N];

class Solution {
    
    vector<vector<int>> fact;
    int n;
    string s;

    int ChangesForSemiPalindrome (int l, int r) {
        int n = r - l + 1;
        int ans = 1e9;
        for(auto &f: fact[n]){
            int change = 0;
            for(int i = 0; i < f; i++){
                int j = l+i, k = r-f+1+i;
                while(j < k){
                    if(s[j] != s[k]) change++;
                    j += f;
                    k -= f;
                }
            }
            ans = min (ans, change);
        }
        return ans;
    }
    
    int fun(int idx, int k){
        if (idx == n) return (k == 0 ? 0 : 1e9);
        if (k == 0) return 1e9;
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int ans = 1e9;
        for(int nxt = idx; nxt < n; nxt++) {
            ans = min(ans, changes[idx][nxt] + fun(nxt+1, k-1));
        }
        return dp[idx][k] = ans;
    }
    
public:
    int minimumChanges(string _s, int k) {
        s = _s;
        n = s.length();
        fact.clear(), fact.resize(n+1);
        for (int j = 1; j <= n; j ++) {
            for (int i = 2*j; i <= n; i += j) fact[i].push_back(j);
        }
        
        //Precomputation
        for (int j = 0; j < n; j ++) {
            for (int k = j; k < n; k ++)
                changes[j][k] = ChangesForSemiPalindrome(j, k);
        }
        
        memset(dp, -1, sizeof(dp));
        return fun(0, k);
    }
};