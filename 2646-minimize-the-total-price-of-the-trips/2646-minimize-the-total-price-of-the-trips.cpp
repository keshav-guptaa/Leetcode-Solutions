class Solution {
public:
    vector<vector<int>> adj;
    int freq[100];
    
    //To count the occurences of each node in trips
    bool dfs(int node, int par, int end){
        if(node == end){
            freq[node]++;
            return 1;
        }
        
        for(auto &it: adj[node]){
            if(it == par) continue;
            freq[node]++;
            if(dfs(it, node, end)) return 1;
            freq[node]--;
        }
        return 0;
    }
    
    //To calculate cost by trying all possibilties 
    pair<int, int> findPrice(int node, int par, vector<int>& p){
        int half = (p[node]/2)*freq[node];
        int nothalf = p[node]*freq[node];
        
        for(auto &it: adj[node]){
            if(it == par) continue;
            pair<int, int> childCost = findPrice(it, node, p);
            half += childCost.second;
            nothalf += min(childCost.first, childCost.second);
        }
        return {half, nothalf};
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        adj.resize(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //To count the occurences of each node in trips
        for(auto &it: trips){
            int st = it[0], dst = it[1];
            dfs(st, -1, dst);
        }
        
        pair<int, int> ans = findPrice(0, -1, price);
        return min(ans.first, ans.second);
    }
};