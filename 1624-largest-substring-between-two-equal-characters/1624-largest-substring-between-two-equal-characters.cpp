class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> last(26, -1);
        int ans = -1;
        for(int i = 0; i < s.length(); i++){
            if(last[s[i]-'a'] != -1) ans = max(ans, i-last[s[i]-'a']-1);
            if(last[s[i]-'a'] == -1) last[s[i]-'a'] = i;
        }
        return ans;
    }
};