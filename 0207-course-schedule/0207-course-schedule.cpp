class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<int> adj[num];
        vector<int> in(num, 0);
        //vector<int> ans;
        for(int i = 0; i < n; i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < num; i++){
            if(!in[i]) q.push(i);
        }
        int ct = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ct++;
            for(auto it: adj[node]){
                in[it]--;
                if(!in[it]) q.push(it);
            }
        }
        
        return ct == num;
    }
};