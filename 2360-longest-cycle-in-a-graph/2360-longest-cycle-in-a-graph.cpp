class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<bool>& vis, vector<bool>& pathvis, int &ans, int distance){
        if(node != -1){
            if(!vis[node]){
                vis[node] = 1;
                pathvis[node] = 1;
                dist[node] = distance;
                dfs(edges[node], edges, dist, vis, pathvis, ans, distance+1);
            }
            else if(pathvis[node]){
                ans = max(ans, distance - dist[node]);
            }
            pathvis[node] = 0;
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, 0);
        vector<bool> pathvis(n, 0);
        vector<int> dist(n, 0);
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs(i, edges, dist, vis, pathvis, ans, 0);
        }
        return ans;
    }
};