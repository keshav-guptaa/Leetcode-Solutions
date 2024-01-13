class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for(auto &it: s) v[it-'a']++;
        for(auto &it: t) v[it-'a']--;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(v[i] > 0) ans += v[i];
        }
        return ans;
    }
};