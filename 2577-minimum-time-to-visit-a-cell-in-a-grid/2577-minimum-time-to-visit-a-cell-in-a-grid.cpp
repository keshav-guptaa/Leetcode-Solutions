class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<int>> time(n, vector<int>(m, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> >pq;
        pq.push({0, 0, 0});
        time[0][0] = 0;
        int dr[] = {0, -1, 1, 0};
        int dc[] = {-1, 0, 0, 1};
        
        while(!pq.empty()){
            auto [t, r, c] = pq.top();
            pq.pop();
            if(r == n-1 && c == m-1) return t;
            //if(time[r][c] > t) continue;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int x = t+1;
                    if(x < grid[nr][nc]){
                        x = grid[nr][nc] + (grid[nr][nc]-x)%2;
                    }
                    if(x < time[nr][nc]){
                        time[nr][nc] = x;
                        pq.push({time[nr][nc], nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};