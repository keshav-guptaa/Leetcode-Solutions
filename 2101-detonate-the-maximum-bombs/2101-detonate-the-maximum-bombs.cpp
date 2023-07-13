class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int &ct){
        vis[node] = 1;
        ct++;
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, ct);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            long long x0 = bombs[i][0], y0 = bombs[i][1], r0 = bombs[i][2];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                long long x = abs(x0 - bombs[j][0]), y = abs(y0 - bombs[j][1]);
                if(x*x + y*y <= r0*r0){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int ct = 0;
            vector<int> vis(n, 0);
            dfs(i, vis, adj, ct);
            ans = max(ans, ct);
        }
        return ans;
    }
};