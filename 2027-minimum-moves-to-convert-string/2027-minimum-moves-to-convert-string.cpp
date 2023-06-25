class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length();
        int ct = 0, i = 0;
        while(i < n){
            if(s[i] == 'X'){
                i += 3;
                ct++;
            }
            else i++;
        }
        return ct;
    }
};