class Solution {
public:
    struct comp {
        bool operator()(string &s1, string &s2) {
            return s1.size()<s2.size();
        }
    };
    
    bool canbrk(int p, string &s, unordered_set<string>& ht) {
        int n = s.size();
        if(p==n) return 1;
        string sub;
        for(int i=p;i<n;i++) if(ht.count(sub+=s[i])&&canbrk(i+1,s,ht)) return 1;
        return 0;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> ht; 
        vector<string> res;
        sort(words.begin(),words.end(),comp());
        for(auto &s:words) {
            if(s.empty()) continue;
            if(canbrk(0,s,ht)) res.push_back(s);
            ht.insert(s);
        }
        return res;
    }
};