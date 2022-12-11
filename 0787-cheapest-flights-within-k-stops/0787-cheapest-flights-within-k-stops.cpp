class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Make an adjacency list.
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> price(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // stops, node, price
        price[src] = 0;
        
        while(!q.empty()){
            int node = q.front().second.first;
            int cost = q.front().second.second;
            int stops = q.front().first;
            q.pop();
            if(stops > k) break;
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjcost = it.second;
                if(adjcost + cost < price[adjNode] && stops <= k){
                    price[adjNode] = adjcost + cost;
                    q.push({stops+1, {adjNode, price[adjNode]}});
                    
                }
            }
        }
        return (price[dst] == 1e9) ? -1 : price[dst];
    }
};