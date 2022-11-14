class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();    
        vector<pair<int, int>> v(n);
        
        for(int i = 0; i < n; i++){
            v[i].first -= growTime[i];
            v[i].second = plantTime[i];
        }
        sort(v.begin(), v.end());
        int cur = 0;
        int tot = 0;
        for(int i = 0; i < n; i++){
            cur += v[i].second;
            tot = max(tot, cur - v[i].first);
        }
        return tot;
    }
};