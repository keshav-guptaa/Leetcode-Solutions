class Solution {
public:
    int videoStitching(vector<vector<int>>& c, int time) {
        //Har second ke liye jumps vector banana h, ye farthest jump from this index store krega
        vector<int> jumps(time+1, -1);
        for(int i = 0; i < c.size(); i++){
            int l = min(c[i][0], time), r = min(c[i][1], time);
            jumps[l] = max(jumps[l], r);
        }
        int maxReach = 0, currReach = 0, ct = 0;
        for(int i = 0; i < time; i++){
            maxReach = max(maxReach, jumps[i]);
            if(i == currReach){
                currReach = maxReach;
                ct++;
            }
            if(currReach == time) return ct;
        }
        return -1;
    }
};