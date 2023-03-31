class Solution {
public:
    int dp[2005][2005];
    
    bool isPalindrome(int i, int j, string &s){
        while(i <= j) if(s[i++] != s[j--]) return false;
        return true;
    }
    
    int f(int i, int j, string &s){
        if(i >= j) return 0;
        if(isPalindrome(i, j, s)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            if(isPalindrome(i, k, s)){
                int x = f(k+1, j, s) + 1;
                ans = min(ans, x);
            }
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        memset(dp, -1, sizeof(dp));
        return f(i, j, s);
    }
};