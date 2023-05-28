class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n =mat.size(), m = mat[0].size();
        vector<int> ans;
        if(mat.size() == 0) return ans;
        int total = n+m-2;
        for(int num = 0; num <= total; num++){
            for(int idx = 0; idx <= num; idx++){
                int r = idx, c = num-idx;
                if(!(num&1)) swap(r, c);
                if(r >= n || c >= m) continue;
                ans.push_back(mat[r][c]);
            }
        }
        return ans;
    }
};