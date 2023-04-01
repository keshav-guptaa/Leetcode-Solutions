class Solution {
public:
    int dp[105][10005];
    
    int f(int k, int n){
        if(n == 1 || n == 0) return n;
        if(k == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        
        int ans = 1e9, s = 1, e = n, temp = 0, mid;
        
        while(s <= e){
            mid = s + (e-s)/2;
            int down = f(k-1, mid-1);
            int up = f(k, n-mid);
            temp = 1 + max(down, up);
            ans = min(ans, temp);
            if(down > up){
                e = mid-1;
            }
            else s = mid+1;
        }
        return dp[k][n] = ans;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return f(k, n);
    }
};