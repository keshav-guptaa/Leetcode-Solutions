class Solution {
public:
    /* Solution 1
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
        */
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int n =mat.size(), m = mat[0].size();
            vector<vector<int>> v(n+m-1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    v[i+j].push_back(mat[i][j]);
                }
            }
            vector<int> ans;
            for(int i = 0; i < n+m-1; i++){
                if(!(i&1)) reverse(v[i].begin(), v[i].end());
                for(auto &x: v[i]) ans.push_back(x);
            }
            return ans;
        }
    
};