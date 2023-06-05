class DSU {
    public:
    vector<int> par, size;
    DSU(int n) {
        par.resize(n+1); size.resize(n+1);
        for(int i = 0; i <= n; i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int node) {
        if(node == par[node]) return node;
        return par[node] = find(par[node]);
    }
    
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
    
    void merge(int u, int v) {
        int p_u = find(u), p_v = find(v);
        if(size[p_v] > size[p_u]) swap(p_u, p_v);
        par[p_v] = p_u;
        size[p_u] += size[p_v];
    }
    
};

class Solution {
public:
    //There are two cases possible:
    //1) Root got extra edge and has one parent now
    //2) Some other node got extra edge and has two parent now.
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        int n = e.size();
        DSU ds(n+1);
        vector<int> in(n+1, -1);
        int e1 = -1, e2 = -1;
        for(int i = 0; i < n; i++){
            if(in[e[i][1]] != -1){
                e2 = in[e[i][1]];
                e1 = i;
                break;
            }
            in[e[i][1]] = i;
        }
        
        for(int i = 0; i < n; i++){
            if(i == e1) continue;   //We are actually ignoring edge 1
            if(ds.isConnected(e[i][0], e[i][1])){
                if(e1 != -1){
                    return e[e2];
                }
                else return e[i];
            }
            ds.merge(e[i][0], e[i][1]);
        }
        return e[e1];
    }
};