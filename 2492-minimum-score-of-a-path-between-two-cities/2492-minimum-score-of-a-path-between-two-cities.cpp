class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        queue<int> q;
        vector<int> vis(n+1, 0);
        q.push(1);
        vis[1] = 1;
        
        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                ans = min(ans, it.second);
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
        return ans;
    }
};