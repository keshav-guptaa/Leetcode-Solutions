class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); 
        dp[0] = {};
        unordered_map<string, int> skills_to_idx;
        for(int i = 0; i < n; i++) skills_to_idx[req_skills[i]] = i;
        
        for(int i = 0; i < people.size(); i++){
            int curr_skill = 0;
            for(auto &it: people[i]) curr_skill |= (1 << skills_to_idx[it]);
            for(auto it = dp.begin(); it != dp.end(); it++){
                int mask = curr_skill | it->first;
                if(dp.count(mask) == 0 || dp[mask].size() > 1 + dp[it->first].size()){
                    dp[mask] = it->second;
                    dp[mask].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};