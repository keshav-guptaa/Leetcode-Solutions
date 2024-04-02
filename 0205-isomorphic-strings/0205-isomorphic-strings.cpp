class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char, char> m1, m2;
        for(int i = 0; i < n; i++){
            if(m1.count(s[i]) > 0 && m1[s[i]] != t[i]) return false;
            else if(m2.count(t[i]) > 0 && m2[t[i]] != s[i]) return false;
            else{
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        return true;
    }
};