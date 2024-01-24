class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> m;
        for(auto &it: mappings) m[it[0]].insert(it[1]);
        
        for(int i = 0; i + sub.length() <= s.length(); i++){
            int j = 0;
            for(; j < sub.length(); j++){
                if(s[i+j] != sub[j] && m[sub[j]].count(s[i+j]) == 0) break;
            }
            if(j == sub.length()) return true;
        }
        return false;
    }
};