class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int>& arr, int n){
        vis[node] = 1;
        if(arr[node] == 0) return true;
        int adj1 = node + arr[node];
        int adj2 = node - arr[node];
        if(adj1 >= 0 && adj1 < n && !vis[adj1]){
            if(dfs(adj1, vis, arr, n)) return true;
        }
        if(adj2 >= 0 && adj2 < n && !vis[adj2]){
            if(dfs(adj2, vis, arr, n)) return true;
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        if(dfs(start, vis, arr, n)) return true;
        return false;
    }
};