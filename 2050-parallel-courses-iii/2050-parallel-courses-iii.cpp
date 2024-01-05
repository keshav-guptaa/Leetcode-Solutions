class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for(auto &it: relations){
            adj[it[0]-1].push_back(it[1]-1);
            in[it[1]-1]++;
        }
        vector<int> dist(n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!in[i]){
                q.push(i);
                dist[i] = time[i];
            } 
        }
        while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto &it: adj[node]){
                    dist[it] = max(dist[it], dist[node]+time[it]);
                    in[it]--;
                    if(!in[it]) q.push(it);
                }
        }
        return *max_element(dist.begin(), dist.end());
    }
};