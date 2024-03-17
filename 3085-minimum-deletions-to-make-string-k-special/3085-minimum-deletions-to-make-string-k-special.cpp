class Solution {
public:
    int dp[27][27], k;
    
    int f(int l, int r, vector<int>& freq){
        if(freq[r] - freq[l] <= k) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        return dp[l][r] = min(freq[l] + f(l+1, r, freq), freq[r]-freq[l]-k + f(l, r-1, freq));
    }
    
    int minimumDeletions(string word, int K) {
        k = K;
        memset(dp, -1, sizeof dp);
        vector<int> freq(26, 0);
        for(auto &it: word) freq[it-'a']++;
        sort(freq.begin(), freq.end());
        return f(0, 25, freq);
    }
};