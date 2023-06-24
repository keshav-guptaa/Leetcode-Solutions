class Solution {
public:
    int time = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, vector<int>& tin,
             vector<int>& low, vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = low[node] = time;
        time++;
        for(auto &it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) bridges.push_back({node, it});
            }
            // why we don't check for bridge in the following condition =>
            // because this adj. node is not parent and it is visited also, hence, both
            // of these are part of cycle and every node present in a cycle can't be a bridge.
            else low[node] = min(low[node], low[it]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<int> adj[n];
        for(auto &it: c){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), tin(n), low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};