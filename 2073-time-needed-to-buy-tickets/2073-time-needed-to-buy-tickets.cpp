class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int ans = 0;
        for(int i = 0; i < t.size(); i++){
            if(i <= k) ans += min(t[i], t[k]);
            else{
                ans += min(t[i], t[k]-1);
            }
        }
        return ans;
    }
};