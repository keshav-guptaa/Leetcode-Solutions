class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> store;
        int n = obs.size(); vector<int> ans(n);
        ans[0] = 1; store.push_back(obs[0]);
        for(int i = 1; i < n; i++){
            if(store.back() <= obs[i]){
                store.push_back(obs[i]);
                ans[i] = store.size();
            } 
            else{
                int idx = upper_bound(store.begin(), store.end(), obs[i]) - store.begin();
                store[idx] = obs[i];
                ans[i] = idx+1;
            }
        }
        return ans;
    }
};