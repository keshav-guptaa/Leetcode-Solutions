class Solution {
public:
    string removeStars(string s) {
        string ans;
        int x = s.length();
        for(int i = 0; i < x; i++){
            if(s[i] == '*' && ans.length() != 0) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};