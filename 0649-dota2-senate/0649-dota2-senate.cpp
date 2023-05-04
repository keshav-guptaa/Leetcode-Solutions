class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r, d;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }
        
        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()) r.push(n++);
            else d.push(n++);
            r.pop(); d.pop();
        }
        return (d.empty()) ? ("Radiant") : ("Dire"); 
    }
};