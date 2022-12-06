class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> in(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it: adj[i]){
                in[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!in[i]) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it: adj[node]){
                in[it]--;
                if(!in[it]) q.push(it);
            }
        }
        
        if(cnt == numCourses) return true;
        else return false;
    }
};