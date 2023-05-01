class DSU {
    public: 
    vector<int> parent, size; 
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int find(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = find(parent[node]); 
    }
    
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    void unite(int u, int v) {
        int p_u = find(u); 
        int p_v = find(v); 
        if(size[p_v] > size[p_u]) swap(p_u, p_v);
        parent[p_v] = p_u;
        size[p_u] += size[p_v]; 
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n), b(n);
        int ct = 0;
        for(auto &e: edges){
            if(e[0] == 3){
                if(a.isConnected(e[1], e[2]) && b.isConnected(e[1], e[2])){
                    ct++;
                }
                else{
                    a.unite(e[1], e[2]);
                    b.unite(e[1], e[2]);
                }  
            }
        }
        
        for(auto &e: edges){
            if(e[0] == 1){
                if(a.isConnected(e[1], e[2])){
                    ct++;
                }
                else a.unite(e[1], e[2]);
            }
            if(e[0] == 2){
                if(b.isConnected(e[1], e[2])){
                    ct++;
                }
                else b.unite(e[1], e[2]);
            }
        }
        
        return (a.size[a.find(1)] == n && b.size[b.find(1)] == n) ? ct : -1;
    }
};