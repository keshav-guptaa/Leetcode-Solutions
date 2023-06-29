class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> compare = intervals[0];
        int ct = 0;
        for(int i = 1; i < n; i++){
            //overlapping
            if(intervals[i][0] < compare[1]){
                if(intervals[i][1] < compare[1]) compare = intervals[i];
                ct++;
            }
            else compare = intervals[i];
        }
        return ct;
    }
};