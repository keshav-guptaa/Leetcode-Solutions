class Solution {
public:
    int n, dp[1 << 15];
    
    int f(int mask, vector<string>& stickers, string& target){
        if(mask == (1 << n) - 1) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = 51;
        for(int i = 0; i < stickers.size(); i++){
            vector<int> freq(26, 0);
            for(auto &c: stickers[i]) freq[c-'a']++;
            int nmask = 0;
            for(int j = 0; j < n; j++){
                if((mask & (1 << j)) == 0){
                    if(freq[target[j]-'a'] > 0){
                        freq[target[j]-'a']--;
                        nmask |= (1 << j);
                    }
                }
            }
            if(nmask != 0) ans = min(ans, 1 + f(nmask | mask, stickers, target));
        }
        return dp[mask] = ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        n = target.length();
        memset(dp, -1, sizeof dp);
        
        int ans = f(0, stickers, target);
        return ans < 16 ? ans : -1;
    }
};