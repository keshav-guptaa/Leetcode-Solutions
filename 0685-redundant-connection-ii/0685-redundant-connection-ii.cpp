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
    // In first case, it will cause formation of cycle . Thus we return the edge causing cycle 
    // In second case, it may or may not create a cycle . But we only have to check those 2            edges that leads to increase in indegree. For this we first remove the later edge and          check if a cycle is present or not . If cyle is present this is nnot the correct edge (1st edge is answer) else its the correct edge (2nd edge is answer).
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        int n = e.size();
        DSU ds(n+1);
        vector<int> in(n+1, -1); //store index of edge
        int e1 = -1, e2 = -1;
        for(int i = 0; i < n; i++){
            if(in[e[i][1]] != -1){
                e1 = in[e[i][1]]; // first edge idx
                e2 = i; // second edge idx
                break;
            }
            in[e[i][1]] = i;
        }
        
        for(int i = 0; i < n; i++){
            if(i == e2) continue;   //We are actually ignoring later edge.
            if(ds.isConnected(e[i][0], e[i][1])){
                if(e1 != -1) return e[e1]; //Case 2(a)
                else return e[i]; // Case 1
            }
            ds.merge(e[i][0], e[i][1]); 
        } 
        return e[e2]; //Case 2(b)
    }
};