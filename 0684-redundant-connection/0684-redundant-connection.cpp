class DisjointSet {
     
public: 
    vector<int> parent, size;
    DisjointSet(int n) {
        //rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> ans(2);
        for(int i = 0; i < n; i++){
            if(ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1])){
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
                continue;
            }
            ds.unionBySize(edges[i][0], edges[i][1]);
        }
        return ans;
    }
};