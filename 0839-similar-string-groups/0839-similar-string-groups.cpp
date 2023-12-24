class Solution {
public:
    bool isSimilar(string &s1, string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
    
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        
        for(auto &x: adj[node]){
            if(!vis[x]) dfs(x, adj, vis);
        }
    }
    
    
    //Convert question into connected components
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ct = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ct++;
                dfs(i, adj, vis);
            }
        }
        return ct;   
    }
};