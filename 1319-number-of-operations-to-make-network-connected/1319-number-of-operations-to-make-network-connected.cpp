class DisjointSet { 
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
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
        return parent[node] = findUPar(parent[node]);  // We are storing answer inn parent[node] 
                                                       // as well to do path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; // Rank increases only when both ultimate parents have same rank
            rank[ulp_u]++; 
        }
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


/* why connect smaller rank to larger rank??
because if we connect smaller to larger then rank will increase and we dont want to increase ranks
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionBySize(u, v);
        }
        if(connections.size() < n-1) return -1;
        int cnt = -1;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) cnt++;
        }
        return cnt;
    }
};