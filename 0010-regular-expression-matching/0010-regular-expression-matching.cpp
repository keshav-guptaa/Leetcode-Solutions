class Solution {
public:
    bool f(int i, int j, string s, string p){
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0){
            
        }
        
        if(s[i] == p[j] || p[j] == '.'){
            return f(i-1, j-1, s, p);
        }
        else{
            if(p[j] == '*'){
                return f(i, j-1, s, p) || f(i-1, j, s, p);
            }
            else return false;
        }
        
    }
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        
        
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
        
            }
        }
        return dp[n][m];
    }
};