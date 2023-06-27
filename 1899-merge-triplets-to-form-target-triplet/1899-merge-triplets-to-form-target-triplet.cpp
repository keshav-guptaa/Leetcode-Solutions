class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int> v(3, INT_MIN);
        for(auto &it: triplets){
            if(it[0] <= t[0] && it[1] <= t[1] && it[2] <= t[2]){
                v[0] = max(v[0], it[0]);
                v[1] = max(v[1], it[1]);
                v[2] = max(v[2], it[2]);
            }
        }
        return v == t;
    }
};