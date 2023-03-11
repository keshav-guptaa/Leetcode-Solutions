class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans = 0, curr = 0;
        for(int i = 0; i < v.size(); i++){
            ans = max(ans, curr + v[i]);
            curr = max(curr, v[i]) - 1;
        }
        return ans;
    }
};