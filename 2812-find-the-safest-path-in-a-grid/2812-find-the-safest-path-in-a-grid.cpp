class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j, 0});
                    grid[i][j] = 0;
                    vis[i][j] = 1;
                } 
            }
        }

        while(!q.empty()){
            auto [r, c, v] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    grid[nr][nc] = v+1;
                    q.push({nr, nc, v+1});
                }
            }
        }
        
        vector<vector<int>> dis(n, vector<int>(n, -1));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(r == n-1 && c == n-1) return d;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && min(d, grid[nr][nc]) > dis[nr][nc] ){
                    dis[nr][nc] = min(d, grid[nr][nc]);
                    pq.push({min(grid[nr][nc], d), {nr, nc}});
                }
            }
        }
        return 0;
    }
};