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
private:
    bool isValid(int nrow, int ncol, int n){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int drow[] = {-1, 0, 0, 1};
                int dcol[] = {0, -1, 1, 0};
                for(int i = 0; i < 4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] 
                       == 1){
                        int nodeNo = row*n + col;
                        int adjNodeNo = nrow*n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int drow[] = {-1, 0, 0, 1};
                int dcol[] = {0, -1, 1, 0};
                set<int> components;
                for(int i = 0; i < 4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] 
                       == 1){
                        components.insert(ds.findUPar(nrow*n + ncol));
                    }
                }
                int sizeTotal = 0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for(int cellNo = 0; cellNo < n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
        
    }
};