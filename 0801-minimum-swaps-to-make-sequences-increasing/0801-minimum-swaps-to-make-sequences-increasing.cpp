class Solution {
public:
    
    int dp[100005][2], n;
    
    int f(vector<int>& n1, vector<int>& n2, int i, int p1, int p2, bool swap){
        if(i == n) return 0;
        if(dp[i][swap] != -1) return dp[i][swap];
        int ans = INT_MAX;

        if(n1[i] > p1 && n2[i] > p2) ans = min(ans, f(n1, n2, i + 1, n1[i], n2[i], false));

        if(n1[i] > p2 && n2[i] > p1) ans = min(ans, 1 + f(n1, n2, i + 1, n2[i], n1[i], true));
        
        return dp[i][swap] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp, -1, sizeof(dp));
        return f(nums1, nums2, 0, -1, -1, false);
    }
};