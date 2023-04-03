class Solution {
public:
    int dp[102][102];
    
    bool f(int i, int j, int k, string& s1, string& s2, string& s3){
        if(i < 0 && j < 0 && k < 0) return true;
        if(i >= 0 && j >= 0 && dp[i][j] != -1) return dp[i][j];
        
        if(i >= 0 && s1[i] == s3[k] && j >= 0 && s2[j] == s3[k]){
            return f(i-1, j, k-1, s1, s2, s3) || f(i, j-1, k-1, s1, s2, s3);
        }
        else if(i >= 0 && s1[i] == s3[k]){
            return f(i-1, j, k-1, s1, s2, s3);
        }
        else if(j >= 0 && s2[j] == s3[k]){
            return f(i, j-1, k-1, s1, s2, s3);
        }
        
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        memset(dp, -1, sizeof(dp));
        return f(s1.length()-1, s2.length()-1, s3.length()-1, s1, s2, s3);
    }
};