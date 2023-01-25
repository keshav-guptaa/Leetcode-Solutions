class Solution {
public:
    void bfs(vector<int>& edges, int src, vector<int> &dist, int n){
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(src);
        dist[src] = 0;
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(edges[node] != -1){
                if(!vis[edges[node]]){
                    vis[edges[node]] = 1;
                    q.push(edges[node]);
                    dist[edges[node]] = dist[node] + 1;
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, 1e9), dist2(n, 1e9);
        bfs(edges, node1, dist1, n);
        bfs(edges, node2, dist2, n);
        int ans = 1e9;
        int node = -1;
        int mx;
        for(int i = 0; i < n; i++){
            mx = max(dist1[i], dist2[i]);
            if(mx < ans){
                ans = mx;
                node = i;
            }
        }
        //ans = (ans == 1e9) ? -1 : ans;
        return node;
    }
};