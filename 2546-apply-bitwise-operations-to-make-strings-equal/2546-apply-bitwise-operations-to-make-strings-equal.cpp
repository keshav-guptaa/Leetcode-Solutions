class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s == target) return true;
        int n = s.length();
        bool f1 = 0, f2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == target[i]){
               if(s[i] == '1') return true; 
            } 
            else{
                if(target[i] == '1') f1 = 1;
                if(s[i] == '1') f2 = 1;
            }
        }
        return f1&f2;
    }
};