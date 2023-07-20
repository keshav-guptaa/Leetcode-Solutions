class Solution {
public:
    long long fuel = 0;
    
    long long dfs(int node, int par, vector<vector<int>>& adj, int seats){
        long long people = 1;
        for(auto &it: adj[node]){
            if(it == par) continue;
            people += dfs(it, node, adj, seats);
        }
        if(node != 0) fuel += (people + seats - 1)/seats;
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};