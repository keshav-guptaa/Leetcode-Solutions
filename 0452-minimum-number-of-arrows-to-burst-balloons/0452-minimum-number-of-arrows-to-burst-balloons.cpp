class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        pair<int, int> comp = {points[0][0], points[0][1]};
        int ans = 1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > comp.second){
                ans++;
                comp = {points[i][0], points[i][1]};
            }
            else{
                comp = {max(points[i][0], comp.first), min(points[i][1], comp.second)};
            }
            //cout << i << " " << ans << " " << comp.first << " " << comp.second << endl;
        }
        return ans;
    }
};