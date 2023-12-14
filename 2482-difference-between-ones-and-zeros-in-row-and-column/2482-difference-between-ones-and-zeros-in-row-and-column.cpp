class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r(n, 0), c(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ones = r[i]+c[j];
                //if(grid[i][j] == 1) ones--;
                int zeros = n+m-ones;
                diff[i][j] = ones-zeros;
            }
        }
        return diff;
    }
};