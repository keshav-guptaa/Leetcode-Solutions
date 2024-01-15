class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> losses(100005, -1);
        for(int i = 0; i < matches.size(); i++){
            int winner = matches[i][0], looser = matches[i][1];
            if(losses[winner] == -1) losses[winner] = 0;
            
            if(losses[looser] == -1) losses[looser] = 1;
            else losses[looser]++;
        }
        
        vector<vector<int>> ans(2);
        
        for(int i = 0; i < losses.size(); i++){
            if(losses[i] == 0) ans[0].push_back(i);
            if(losses[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};