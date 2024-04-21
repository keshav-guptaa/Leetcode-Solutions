#define pi pair<int, int>
class Solution {
public:
    vector<long long> dijkstra(int src, int dst, vector<vector<vector<int>>>& adj){
        int n = adj.size();
        vector<long long> dist(n, 1e14);
        priority_queue<pi, vector<pi>, greater<>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(node == dst) break;
            for(auto& it: adj[node]){
                if(it[1] + d < dist[it[0]]){
                    dist[it[0]] = it[1] + d;
                    pq.push({d + it[1], it[0]});
                }   
            }
        }
        return dist;
    }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        int m = e.size();
        vector<vector<vector<int>>> adj(n);
        for(int i = 0; i < m; i++){
            adj[e[i][0]].push_back({e[i][1], e[i][2]});
            adj[e[i][1]].push_back({e[i][0], e[i][2]});
        }
        vector<long long> d1 = dijkstra(0, n-1, adj);
        vector<long long> d2 = dijkstra(n-1, 0, adj);
        long long mx = d1[n-1];
        vector<bool> ans(m, 0);
        if(mx == 1e14) return ans;
        for(int i = 0; i < m; i++){
            if(d1[e[i][0]] + d2[e[i][1]] + e[i][2] == mx || d2[e[i][0]] + d1[e[i][1]] +                 e[i][2] == mx){
                ans[i] = 1;
            } 
        }
        return ans;
    }
};