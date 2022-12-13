class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) adj[i][i] = 0;
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int smallest = -1;
        int prev = 1e9;
        int temp = 0;
        for(int i = 0; i < n; i++){
            temp = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= distanceThreshold) temp++;
            }
            if(temp <= prev){
                smallest = i;
                prev = temp;
            }
        }
        return smallest;
    }
};