class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        int x = grid.size(), y = grid[0].size();
        vector<vector<int>> vis(x, vector<int>(y, 0));
        int n = q.size();
        vector<pair<int, int>> qp;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            qp.push_back({q[i], i});
        }
        sort(qp.begin(), qp.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        vis[0][0] = 1;
        pq.push({-grid[0][0], {0, 0}});
        
        int ct = 0;
        for(int i = 0; i < n; i++){
            int ele = qp[i].first, idx = qp[i].second;
            while(!pq.empty()){
                auto it = pq.top();
                int r = it.second.first, c = it.second.second;
                int curr = -it.first;
                
                if(ele <= curr) break;
                else{
                    pq.pop();
                    ct++;
                }
                
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k], nc = c + dc[k];
                    if(nr >= 0 && nr < x && nc >= 0 && nc < y && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        pq.push({-grid[nr][nc], {nr, nc}});
                    }
                }
                
            }
            ans[idx] = ct;
        }
        return ans;
    }
};