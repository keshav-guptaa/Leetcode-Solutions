class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int &ans){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[abs(it)]){
                if(it >= 0) ans++;
                dfs(abs(it), vis, adj, ans);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        
        vector<int> vis(n, 0);
        int ans = 0;
        dfs(0, vis, adj, ans);
        return ans;
    }
};