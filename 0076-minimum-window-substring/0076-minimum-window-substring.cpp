class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(int i = 0; i < t.length(); i++) m[t[i]]++;
        int count = m.size(), iidx = -1, jidx = -1, ans = INT_MAX;
        int n = s.length();
        int i = 0, j = 0;
        while(j < n){
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0) count--;
            }
            
            if(count == 0){
                while(count == 0){
                    if(j-i+1 < ans){
                        ans = j-i+1;
                        iidx = i;
                        jidx = j;
                    }
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(m[s[i]] > 0) count++;
                    }
                    i++;
                }
            }
            j++;
        }
        string as = "";
        if(iidx == -1) return as;
        for(int k = iidx; k <= jidx; k++) as += s[k];
        return as;
    }
};