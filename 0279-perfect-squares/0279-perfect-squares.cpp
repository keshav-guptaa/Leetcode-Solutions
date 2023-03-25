class Solution {
public:
    
    int memodp(int n,vector<int> &dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int minvalue=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int minperfectsquarepro=memodp(n-i*i,dp);
            minvalue=min(minvalue,minperfectsquarepro+1);
        }
        
        return dp[n] = minvalue;  
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return memodp(n,dp);
    }
};