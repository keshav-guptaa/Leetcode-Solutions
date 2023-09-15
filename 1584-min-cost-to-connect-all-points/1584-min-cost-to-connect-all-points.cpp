class DSU {
    public: 
    vector<int> p, s; 
    DSU(int n){
        p.resize(n+1); s.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            p[i] = i; s[i] = 1; 
        }
    }

    int find(int u){
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    bool isConnected(int u, int v){
        return find(u) == find(v);
    }
    
    void merge(int u, int v){
        int p_u = find(u), p_v = find(v); 
        if(p_u == p_v) return;
        if(s[p_v] > s[p_u]) swap(p_u, p_v);
        p[p_v] = p_u;
        s[p_u] += s[p_v]; 
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        DSU ds(n);
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weight = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                adj.push_back({weight, {i, j}});
            }
        }

        int ans = 0;
        sort(adj.begin(), adj.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        for(int i = 0; i < adj.size(); i++){
            int u = adj[i].second.first, v = adj[i].second.second;
            if(!ds.isConnected(u, v)){
                ds.merge(u, v);
                ans += adj[i].first;
            }
        }
        return ans;
    }
};