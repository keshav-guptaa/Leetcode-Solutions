class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int ans = abs(target[0]) + abs(target[1]);
        int x = ghosts.size();
        int temp = 0;
        for(int i = 0; i < x; i++){
            temp = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            if(temp <= ans) return false;
        }
        return true;
    }
};