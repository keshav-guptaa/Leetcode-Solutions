class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(grid[0][0] == 1) return -1;
        queue< pair< int, pair<int, int> > > q;
        q.push({1, {0, 0}});
        vis[0][0] = 1;
        while(!q.empty()){
            //cout << 1 << endl;
            auto it = q.front();
            q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int d = it.first;
            if(row == n-1 && col == n-1){
                return d;
            }
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({d+1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
        
    }
};