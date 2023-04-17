class DisjointSet {
    public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
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

    void unionBySize(int u, int v) {
        int p_u = find(u); 
        int p_v = find(v); 
        if(p_u == p_v) return; 
        if(size[p_u] < size[p_v]) {
            parent[p_u] = p_v; 
            size[p_v] += size[p_u]; 
        }
        else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v]; 
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])                                 ds.unionBySize(i, j);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) ans++;
        }
        return n-ans;
    }
};