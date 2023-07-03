class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        
        for(int i = 0; i <= n; i++){
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            jumps[l] = max(jumps[l], r); //from l, that's farthest I can jump to right
        }
        
        int ct = 0, currReach = 0, maxReach = 0;
        for(int i = 0; i < n; i++){
            maxReach = max(maxReach, jumps[i]);
            
            if(i == currReach){
                currReach = maxReach;
                ct++;
            }
        }
        
        return currReach >= n ? ct: -1;
    }
};