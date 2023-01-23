class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> in(n, 0);
        for(int i = 0; i < n; i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                in[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                in[it]--;
                if(!in[it]) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};