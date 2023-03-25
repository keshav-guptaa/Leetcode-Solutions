class Solution {
public:
    int bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        vis[node] = 1;
        int cnt = 1;
        q.push(node);
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it: adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int x = bfs(i, adj, vis);
                ans += sum*x;
                sum += x;
            }
        }
        
        return ans;
    }
};