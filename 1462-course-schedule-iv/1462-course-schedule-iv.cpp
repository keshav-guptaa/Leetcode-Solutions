class Solution {
public:
    bool dfs(int node, int target, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        if(node == target) return true;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it, target, vis, adj)) return true;
            }
        }
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for(auto &it: pre){
            adj[it[0]].push_back(it[1]);
        }
        int sz = q.size();
        vector<bool> ans(sz);
        for(int i = 0; i < sz; i++){
            vector<int> vis(n, 0);
            ans[i] = dfs(q[i][0], q[i][1], vis, adj);
        }
        return ans;
    }
};