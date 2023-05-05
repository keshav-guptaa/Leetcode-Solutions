class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fL, vector<vector<int>>& sL) {
        vector<vector<int>> ans;
        int n = fL.size(), m = sL.size(), i = 0, j = 0;
        while(i < n && j < m){
            int left = max(fL[i][0], sL[j][0]);
            int right = min(fL[i][1], sL[j][1]);
            if(left <= right) ans.push_back({left, right});
            if(fL[i][1] < sL[j][1]) i++;
            else j++;
        }
        return ans;
    }
};