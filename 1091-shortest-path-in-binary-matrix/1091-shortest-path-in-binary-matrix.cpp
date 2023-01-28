class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int d = it.second;
            if(row == n-1 && col == n-1) return d;
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
                       && grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, d+1});
                    }
                }
            }
        }
        
        return -1;
    }
};