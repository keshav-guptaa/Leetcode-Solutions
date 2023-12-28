class Solution {
public:
    vector<int> dp, ans;
    vector<vector<int>> adj;
    
    int dfs(int node, int par){
        dp[node] = 0;
        for(auto &it: adj[node]){
            if(abs(it) == par) continue;
            dp[node] += dfs(abs(it), node);
            if(it < 0) dp[node]++;
        }
        return dp[node];
    }
    
    void dfs2(int node, int par){
        for(auto &it: adj[node]){
            if(abs(it) == par) continue;
            ans[abs(it)] = ans[node] + ((it < 0) ? -1 : 1); 
            dfs2(abs(it), node);
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        dp.resize(n); adj.resize(n); ans.resize(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]); //To make directed graph to undirected graph
        }
        dfs(0, -1);
        ans[0] = dp[0];
        dfs2(0, -1);
        return ans;
    }
};