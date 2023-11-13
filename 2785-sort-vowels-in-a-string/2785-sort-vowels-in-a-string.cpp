class Solution {
public:
    
    string sortVowels(string s) {
        int n = s.length();
        vector<int> idx;
        vector<char> ch;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i]               == 'o' || s[i] == 'u'){
                idx.push_back(i);
                ch.push_back(s[i]);
            }
        }
        sort(ch.begin(), ch.end());
        string t = s;
        for(int i = 0; i < ch.size(); i++){
            t[idx[i]] = ch[i];
        }
        return t;
    }
};