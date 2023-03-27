class Solution {
public:
    bool isAllStars(string &p, int j){
        for(int i=0; i<=j; i++){
            if(p[i] != '*') return false;
        }
        return true;
    }
    
    bool memoization(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) return isAllStars(p, j);
        
        if(dp[j][i] != -1) return dp[j][i];
        
        if(s[i] == p[j] || p[j] == '?'){
            return dp[j][i] = memoization(i-1, j-1, s, p, dp);
        }
        else{
            if(p[j] == '*'){
                return dp[j][i] = memoization(i-1, j, s, p, dp) || memoization(i, j-1, s, p, dp);
            }
            else return false;
        }
        
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(n-1, m-1, s, p, dp);
    }
};