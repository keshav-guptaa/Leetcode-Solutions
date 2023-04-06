class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]){
            if(a[1] < b[1]) return true;
            else if(a[1] == b[1]){
                if(a[2] < b[2]) return true;
                return false;
            }
        }
        return false;
    }
    
    int maxHeight(vector<vector<int>>& cub) {
        int n = cub.size();
        for(auto &x: cub) sort(x.begin(), x.end());
        sort(cub.begin(), cub.end(), comp);
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            h[i] = cub[i][2];
            for(int j = 0; j < i; j++){
                if(cub[j][0] <= cub[i][0] && cub[j][1] <= cub[i][1] && cub[j][2] <= cub[i][2]){
                    if(h[j]+cub[i][2] > h[i]) h[i] = h[j] + cub[i][2];
                }
            }
        }
        return *max_element(h.begin(), h.end());
    }
};