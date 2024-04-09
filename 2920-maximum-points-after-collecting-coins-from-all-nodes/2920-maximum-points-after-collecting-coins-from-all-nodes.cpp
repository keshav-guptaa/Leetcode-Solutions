class Solution {
public:
    vector<int> g[100005];
    int dp[100005][15];
    int k;
    
    int f(int node, int ops, int parent, vector<int>& c){
        if(ops > 13) return 0;
        if(dp[node][ops] != -1) return dp[node][ops];
        
        int p1 = (c[node] >> ops) - k;
        int p2 = c[node] >> (ops+1);
        for(auto& it: g[node]){
            if(it == parent) continue;
            p1 += f(it, ops, node, c);
            p2 += f(it, ops+1, node, c);
        }
        return dp[node][ops] = max(p1, p2);
    }
    
    int maximumPoints(vector<vector<int>>& e, vector<int>& c, int K) {
        k = K;
        int n = c.size();
        memset(dp, -1, sizeof dp);
        for(auto& it: e){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        return f(0, 0, -1, c);
    }
};