class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        unordered_map<int, vector<int>> s_to_b;
        for(int i = 0; i < r.size(); i++){
            for(auto &it: r[i]) s_to_b[it].push_back(i);
        }
        unordered_set<int> bus, st;
        queue<pair<int, int>> q;
        q.push({s, 0});
        while(!q.empty()){
            auto [stop, ct] = q.front();
            q.pop();
            if(stop == t) return ct;
            
            for(auto &it: s_to_b[stop]){
                if(bus.find(it) != bus.end()) continue;
                bus.insert(it);
                for(auto &stops: r[it]){
                    if(st.find(stops) != st.end()) continue;
                    st.insert(stops);
                    q.push({stops, ct+1});
                }
            }
        }
        return -1;
    }
};