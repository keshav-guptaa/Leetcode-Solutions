class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        for(int i = 0; i < n; i++){
            for(int j = i+1, y = INT_MIN; j < n; j++){ 
                if(p[j][1] <= p[i][1] && p[j][1] > y){
                    y = p[j][1];
                    ans++;
                }
            }
        }
        return ans;
    }
};