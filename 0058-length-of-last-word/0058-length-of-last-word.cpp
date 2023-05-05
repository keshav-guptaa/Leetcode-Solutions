class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), ct = 0;
        bool f = 0;
        for(int i = n-1; i >= 0; i--){
            if(f == 1 && s[i] != ' ') ct++;
            if(f == 0 && s[i] != ' '){
                ct++;
                f = 1;
            }
            
            if(f == 1 && s[i] == ' '){
                f = 0;
                break;
            }
            
        }
        return ct;
    }
};