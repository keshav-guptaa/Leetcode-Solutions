#define pip pair<int, pair<int, int>>
class Solution {
public:
    int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> t(row+1, vector<int>(col+1));
        vector<vector<int>> vis(row+1, vector<int>(col+1, 0));
        for(int i = 1; i <= cells.size(); i++){
            t[cells[i-1][0]][cells[i-1][1]] = i;
        }
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        for(int i = 1; i <= col; i++){
            pq.push({-t[1][i], {1, i}});
        }
        
        while(!pq.empty()){
            int time = -pq.top().first;
            int r = pq.top().second.first, c = pq.top().second.second;
            pq.pop();
            if(vis[r][c]) continue;
            vis[r][c] = 1;
            if(r == row) return time-1;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 1 && nr <= row && nc >= 0 && nc <= col && !vis[nr][nc]){
                    pq.push({-min(time, t[nr][nc]), {nr, nc}});
                }
            }
        }
        return 0;
    }
};