class Solution {
public:
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int mx = 0, ans = 0;
        for(int i = p.size()-1; i >= 0; i--){
            if(p[i][1] < mx) ans++;
            mx = max(mx, p[i][1]);
        }
        return ans;
    }
};