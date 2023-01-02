class Solution {
public:
    bool detectCapitalUse(string word) {
        int f = 0;
        int ct = 0;
        if(word[0] - 'A' < 26) f = 1;
        for(int i = 0; i < word.length(); i++){
            if(word[i] - 'A' < 26) ct++;
        }
        return (f == ct) || (ct == word.length());
    }
};