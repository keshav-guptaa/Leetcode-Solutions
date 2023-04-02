class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        vector<int> ans;
        sort(p.begin(), p.end());
        int n = s.size(), m = p.size();
        int mx = p[m-1];
        for(int i = 0; i < n; i++){
            long f = (suc + s[i] - 1)/s[i];

            int idx = lower_bound(p.begin(), p.end(), f) - p.begin();
            ans.push_back(m-idx);
        }
        return ans;
    }
};