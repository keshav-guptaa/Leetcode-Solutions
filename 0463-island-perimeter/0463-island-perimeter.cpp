class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 1){
                    ans += 4;
                    if(i > 0 && g[i-1][j] == 1) ans -= 2;
                    if(j > 0 && g[i][j-1] == 1) ans -= 2;
                } 
            }
        }
        return ans;
    }
};