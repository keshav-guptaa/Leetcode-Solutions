class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0, n = t.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == t[j]) j++;
        }
        return n-j;
    }
};