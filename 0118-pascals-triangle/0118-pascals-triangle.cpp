class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev, curr;
        for(int i = 1; i <= numRows; i++){
            curr.resize(i);
            curr[0] = 1, curr[i-1] = 1;
            for(int j = 1; j < i-1; j++){
                curr[j] = prev[j] + prev[j-1];
            }
            prev = curr;
            ans.push_back(curr);
        }
        return ans;
    }
};