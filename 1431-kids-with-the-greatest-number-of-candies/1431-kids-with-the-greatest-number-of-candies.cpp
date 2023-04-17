class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int extra) {
        int mx = *max_element(can.begin(), can.end());
        int n = can.size();
        vector<bool> ans(n);
        for(int i = 0; i < n; i++){
            if(can[i]+extra >= mx) ans[i] = 1;
            else ans[i] = 0;
        }
        return ans;
    }
};