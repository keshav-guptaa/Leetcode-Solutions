class Solution {
public:
    int minCost(string colors, vector<int>& t) {
        int i = 0, n = colors.length(), ans = 0, ct = t[0], mx = t[0];
        for(int j = 1; j < n; j++){
            if(colors[j] == colors[i]){
                ct += t[j];
                mx = max(mx, t[j]);
            }
            else{
                ans += (ct-mx);
                ct = t[j];
                mx = t[j];
                i = j;
            }
        }
        ans += (ct-mx);
        return ans;
    }
};