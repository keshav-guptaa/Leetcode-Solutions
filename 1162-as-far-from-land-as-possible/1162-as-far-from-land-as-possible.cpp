class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair <pair<int, int>, int> > q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({{i, j}, 0});
            }
        }
        int mx = 0;
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            mx = max(mx, d);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && grid[nrow][ncol] == 0){
                    grid[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }
        
        return (mx == 0) ? -1 : mx;
    }
};