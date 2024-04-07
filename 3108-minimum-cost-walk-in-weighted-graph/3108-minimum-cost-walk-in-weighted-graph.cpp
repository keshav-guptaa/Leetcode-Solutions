class DSU {
    public: 
    vector<int> p, s, andd; 
    DSU(int n){
        p.resize(n+1); s.resize(n+1), andd.resize(n+1, 131071); 
        for(int i = 0; i <= n; i++) {
            p[i] = i; s[i] = 1; 
        }
    }
    
    //path compression
    int find(int u){
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }
    
    bool isConnected(int u, int v){
        return find(u) == find(v);
    }

    void merge(int u, int v, int wt){
        int p_u = find(u), p_v = find(v); 
        andd[p_u] = andd[p_v] = andd[p_u] & andd[p_v] & wt;
        if(p_u == p_v) return;
        if(s[p_v] > s[p_u]) swap(p_u, p_v);
        p[p_v] = p_u;
        s[p_u] += s[p_v]; 
    }
    
    int minWeight(int u, int v){
        if(u == v) return 0;
        else if(isConnected(u, v)) return andd[find(u)];
        return -1;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        DSU ds(n);
        for(auto& it: edges) ds.merge(it[0], it[1], it[2]);
        int m = q.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            ans[i] = ds.minWeight(q[i][0], q[i][1]);
        }
        return ans;
    }
};