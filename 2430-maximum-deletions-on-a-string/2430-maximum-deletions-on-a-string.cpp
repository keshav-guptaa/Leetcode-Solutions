class Solution {
public:
    int n;
    vector<int> calcLPS(string& pattern){
        int n = pattern.length(), i = 1, len = 0;
        vector<int> lps(n, 0);
        
        while(i < n){
            if(pattern[i] == pattern[len]) lps[i++] = ++len;
            else{
                if(len != 0) len = lps[len-1];
                else i++;
            }
        }
        return lps;
    }
    
    int f(int idx, string& s, vector<int>& dp){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        string temp = s.substr(idx);
        vector<int> lps = calcLPS(temp);
        int ans = 1;
        for(int j = 0; j < lps.size(); j++){
            if(j+1 == lps[j]*2) ans = max(ans, 1 + f(idx+lps[j], s, dp));
        }
        return dp[idx] = ans;
    }
    
    int deleteString(string s) {
        n = s.length();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};