class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m, vis;
        for(auto &it: arr) m[it]++;
        for(auto &it: m){
            vis[it.second]++;
            if(vis[it.second] == 2) return false;
        }
        return true;
    }
};