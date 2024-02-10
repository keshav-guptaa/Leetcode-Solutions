class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        //Odd length string
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l--] == s[r++]) ans++;
                else break;
            }
        }
        //Even length string
        for(int i = 0; i < n-1; i++){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l--] == s[r++]) ans++;
                else break;
            }
        }
        return ans;
    }
};