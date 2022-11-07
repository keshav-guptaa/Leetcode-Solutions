class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
        int curr = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'R'){
                curr++;
            }
            else curr--;
            
            if(curr == 0) count++;
        }
        return count;
    }
};