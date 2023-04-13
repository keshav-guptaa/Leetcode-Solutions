class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1]; 
        for(auto &t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int> dist(n+1, -1);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        
        while(!pq.empty()){
            auto[d1, node] = pq.top();
            pq.pop();
            for(auto [it, d2]: adj[node]){
                if(dist[it] == -1 || d1+d2 < dist[it]){
                    dist[it] = d1+d2;
                    pq.push({d1+d2, it});
                }
            }
        }
        //for(int i = 0; i <= n; i++) cout << dist[i] << " ";
        int neg = count(dist.begin(), dist.end(), -1);
        if(neg != 0) return -1;
        return *max_element(dist.begin(), dist.end());
    }
};