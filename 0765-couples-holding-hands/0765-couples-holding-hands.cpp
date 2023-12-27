class DSU {
    public: 
    vector<int> p, s; 
    DSU(int n){
        p.resize(n+1); s.resize(n+1); 
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), ans = 0;
        DSU ds(n);
        for(int i = 0; i < n; i += 2) ds.merge(row[i], row[i+1]);
        for(int i = 0; i < n; i += 2){
            if(!ds.isConnected(i, i+1)){
                ans++;
                ds.merge(i, i+1);
            }
        }
        return ans;
    }
};