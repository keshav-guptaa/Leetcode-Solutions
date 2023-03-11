class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int mx = 0, ans = 0;
        for(int i = n-1; i >= 0; i--){
            mx = max(mx, p[i]);
            ans = max(ans, mx-p[i]);
        }
        return ans;
    }
};