class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> vis(rooms.size(), 0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: rooms[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        bool f = 1;
        for(auto it: vis){
            if(it == 0){
                f = 0;
                break;
            }
        }
        return f;
    }
};