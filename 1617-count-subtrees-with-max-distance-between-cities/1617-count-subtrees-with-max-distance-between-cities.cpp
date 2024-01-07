class Solution {
public:
    int findMaxDistance(int mask, vector<vector<int>>& dis, int n){
        int edges = 0, nodes = 0, mx = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                nodes++;
                for(int j = i+1; j < n; j++){
                    if(mask & (1 << j)){
                        edges += (dis[i][j] == 1);
                        mx = max(mx, dis[i][j]);
                    }
                }
            }
        }
        
        if(edges == nodes-1) return mx;
        return -1;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& e) {
        vector<vector<int>> dis(n, vector<int>(n, n+1));
        for(auto &it: e){
            dis[it[0]-1][it[1]-1] = dis[it[1]-1][it[0]-1] = 1;
        } 
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        vector<int> ans(n-1, 0);
        for(int mask = 0; mask < (1 << n); mask++){
            int d = findMaxDistance(mask, dis, n);
            if(d > 0) ans[d-1]++;
        }
        return ans;
    }
};