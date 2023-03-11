class Solution {
public:
    int maxProfit(vector<int>& p) {
        int f = 0;
        int n = p.size(), buy = 0, ans = 0;
        for(int i = 0; i < n-1; i++){
            if(f == 1){
                if(p[i] >= p[i+1]){
                    f = 1-f;
                    ans += p[i]-buy;
                }
            }
            else{
                if(p[i] < p[i+1]){
                    buy = p[i];
                    f = 1-f;
                }
            }
        }
        if(f == 1 && p[n-1] > buy){
            ans += p[n-1]-buy;
        }
        return ans;
    }
};