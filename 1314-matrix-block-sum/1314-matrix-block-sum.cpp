class Solution {
public:
    int rsz, csz;
    int extract(int r, int c, vector<vector<int>>& sum){
        if(r < 0 || c < 0) return 0;
        if(r >= rsz) r = rsz-1;
        if(c >= csz) c = csz-1;
        return sum[r][c];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        rsz = mat.size();
        csz = mat[0].size();
        
        vector<vector<int>> sum(rsz, vector<int>(csz, 0));
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                sum[i][j] = mat[i][j] + extract(i-1, j, sum) + extract(i, j-1, sum) - extract(i-1, j-1, sum);
            }
        }
        
        vector<vector<int>> ans(rsz, vector<int>(csz, 0));
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                ans[i][j] = extract(i+k, j+k, sum) - extract(i-k-1, j+k, sum) - extract(i+k, j-k-1, sum) + extract(i-k-1, j-k-1, sum);
            }
        }
        return ans;
        
    }
};