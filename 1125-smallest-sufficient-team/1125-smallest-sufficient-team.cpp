class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); // reserve space and avoid hash collisions
        dp[0] = {}; //necessary for initial interation of dp map
        unordered_map<string, int> skills_to_idx;
        for(int i = 0; i < n; i++) skills_to_idx[req_skills[i]] = i;
        
        for(int i = 0; i < people.size(); i++){
            int curr_skill = 0;
            for(auto &it: people[i]) curr_skill |= (1 << skills_to_idx[it]);
            for(auto it = dp.begin(); it != dp.end(); it++){
                int mask = it->first, nmask = curr_skill | mask;
                if(dp.count(nmask) == 0 || dp[nmask].size() > 1 + dp[mask].size()){
                    dp[nmask] = it->second; // put old mask elements
                    dp[nmask].push_back(i); // put current element
                }
            }
        }
        return dp[(1<<n)-1];
    }
};