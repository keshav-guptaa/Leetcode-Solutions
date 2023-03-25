class Solution {
public:
    void bfs(int node, vector<int> adj[], vector<int> &vis, int &cnt){
        queue<int> q;
        vis[node] = 1;
        cnt++;
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
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ct;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            if(!vis[i]){
                bfs(i, adj, vis, cnt);
                ct.push_back(cnt);
            }
        }
        long long ans = 0;
        long long sum = 0;
        for(auto it: ct){
            ans += sum*it;
            sum += it;
        }
        return ans;
    }
};