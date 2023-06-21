class Solution {
public:
    unordered_map<string, bool> m;
    
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(s1 == s2) return 1;
        if(n == 1) return 0;
        
        string key = s1 + " " + s2;
        
        if(m.find(key) != m.end()) return m[key];
        
        for(int i = 1; i < n; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                            isScramble(s1.substr(i),s2.substr(i))){
                return m[key] = 1;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i)) && 
                            isScramble(s1.substr(i),s2.substr(0, n-i))){
                return m[key] = 1;
            }
        }
        return m[key] = 0;
    }
};