class Solution {
public:
    vector<long long> ans;
    
    vector<long long> dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& cost){
        vector<long long> c;
        for(auto &it: adj[node]){
            if(it == parent) continue;
            vector<long long> temp = dfs(it, node, adj, cost);
            for(auto &it: temp) c.push_back(it);
        }
        c.push_back(cost[node]);
        int n = c.size();
        if(n >= 3){
            sort(c.begin(), c.end());
            ans[node] = max(c[n-1]*c[n-2]*c[n-3], c[0]*c[1]*c[n-1]);
            if(ans[node] < 0) ans[node] = 0;
        }
        else ans[node] = 1;
        if(c.size() <= 5) return c;
        return {c[0], c[1], c[n-3], c[n-2], c[n-1]};
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        ans.resize(n);
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, -1, adj, cost);
        return ans;
    }
};