class Solution {
public:
    int memo(int num, vector<int>& dp, bool &f){
        if(num == 0) return 1;
        if(dp[num] != -1) return dp[num];
        
        int product = INT_MIN;
        if(f){
            f = 1;
            for(int i = 1; i <= num; i++){
                product = max(product, i*memo(num-i, dp, f));
            }
        }
        else{
            f = 1;
            for(int i = 1; i < num; i++){
                product = max(product, i*memo(num-i, dp, f));
            }
        }
        return dp[num] = product;
    }
    
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        bool f = 0;
        return memo(n, dp, f);
    }
};