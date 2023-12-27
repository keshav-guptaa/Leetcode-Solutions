class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) { 
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < meetings.size(); i++){
            adj[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }

		vector<int> vis(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push({0, firstPerson});
        q.push({0, 0});
		 
        while(!q.empty()){
            auto [time, node] = q.top();
            q.pop();
            //cout << node << " ";
            if(vis[node]) continue;
            vis[node] = 1;
			 
            for(auto &it: adj[node]){
                if(!vis[it.first] && time <= it.second){
                    q.push({it.second, it.first});
                }
            }
        }
        
		vector<int> ans;
        for(int i = 0; i < n; i++){
            //cout << vis[i] << " ";
            if(vis[i]) ans.push_back(i);        
            
        }
        return ans;
    }
};