class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n, vector<int>(n, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        time[0][0] = grid[0][0];
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, 1, -1, 0};
        
        while(!pq.empty()){
            auto [t, r, c] = pq.top();
            pq.pop();
            if(r == n-1 && c == n-1) return t;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(max(grid[nr][nc], t) < time[nr][nc]){
                        time[nr][nc] = max(grid[nr][nc], t);
                        pq.push({time[nr][nc], nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};