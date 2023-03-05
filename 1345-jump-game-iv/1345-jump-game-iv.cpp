class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[arr[i]].push_back(i);
        }
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int jumps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int idx = q.front();
                q.pop();
                if(idx == n-1) return jumps;
                
                if(idx-1 >= 0 && !vis[idx-1]){
                    vis[idx-1] = 1;
                    q.push(idx-1);
                }
                if(idx+1 < n && !vis[idx+1]){
                    vis[idx+1] = 1;
                    q.push(idx+1);
                }
                for(auto it: m[arr[idx]]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
                m[arr[idx]].clear();
            }
            jumps++;
        }
        return -1;
    }
};