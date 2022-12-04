class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                q.push(i);
                vis[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto x: graph[node]){
                        if(vis[x] == -1){
                           vis[x] = (vis[node] == 0) ? 1 : 0;
                           q.push(x);
                        }
                        else if(vis[node] == vis[x]){
                           return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};