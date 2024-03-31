class Solution {
public:
    
    int minimumDistance(vector<vector<int>>& p) {
        int n = p.size();
        map<int, int> m1, m2;
        for(int i = 0; i < n; i++){
            m1[p[i][0] + p[i][1]]++;
            m2[p[i][0] - p[i][1]]++;
        } 
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            int add = p[i][0] + p[i][1], sub = p[i][0] - p[i][1];
            m1[add]--;
            m2[sub]--;
            if(m1[add] == 0) m1.erase(add);
            if(m2[sub] == 0) m2.erase(sub);
            ans = min(ans, max(m1.rbegin()->first-m1.begin()->first, m2.rbegin()->first-m2.begin()->first));
            m1[add]++;
            m2[sub]++;
        }
        return ans;
    }
};