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

    void unite(int u, int v) {
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
    bool static compare(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        DSU ds(n);
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), compare);
        sort(edgeList.begin(), edgeList.end(), compare);
        int j = 0;
        for(int i = 0; i < queries.size(); i++){
            for(; j < edgeList.size() && edgeList[j][2] < queries[i][2]; j++){
                ds.unite(edgeList[j][0], edgeList[j][1]);
            }
            ans[queries[i][3]] = ds.find(queries[i][0]) == ds.find(queries[i][1]);
            
        }
        return ans;
    }
};