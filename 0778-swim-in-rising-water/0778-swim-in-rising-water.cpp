#define ti tuple<int, int, int>
class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
        
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<ti, vector<ti>, greater<ti>> pq; 
        pq.push({grid[0][0], 0, 0});
        dis[0][0] = grid[0][0];
        
        while(!pq.empty()){
            auto [d, r, c] = pq.top();
            pq.pop();
            if(r == n-1 && c == m-1) return d;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dis[nr][nc] > max(d, grid[nr]                    [nc])){
                    dis[nr][nc] = max(d, grid[nr][nc]);
                    pq.push({dis[nr][nc], nr, nc});
                }
                    
            }
        }
        return -1;
    }
};