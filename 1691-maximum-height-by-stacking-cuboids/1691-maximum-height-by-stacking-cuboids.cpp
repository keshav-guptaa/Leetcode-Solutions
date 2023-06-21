class Solution {
public:
    
    int maxHeight(vector<vector<int>>& cub) {
        int n = cub.size();
        for(auto &x: cub) sort(x.begin(), x.end());
        sort(cub.begin(), cub.end());
        vector<int> h(n);
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            h[i] = cub[i][2];
            for(int j = 0; j < i; j++){
                if(cub[j][0] <= cub[i][0] && cub[j][1] <= cub[i][1] && cub[j][2] <= cub[i][2]){
                    if(h[j]+cub[i][2] > h[i]) h[i] = h[j] + cub[i][2];
                }
            }
            mx = max(mx, h[i]);
        }
        return mx;
    }
};