class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                in[it]--;
                if(!in[it]) q.push(it);
            }
        }
    
        if(topo.size() == numCourses) return topo;
        else{
            topo.clear();
            return topo;
        }
    }
};