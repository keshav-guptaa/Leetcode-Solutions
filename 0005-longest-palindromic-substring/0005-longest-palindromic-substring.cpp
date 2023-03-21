class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mx = 0;
        string ans;
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    if(r-l+1 > mx){
                        mx = r-l+1;
                        ans = s.substr(l, mx);
                    }
                }
                else break;
                l--;
                r++;
            }
        }
        for(int i = 0; i < n-1; i++){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    if(r-l+1 > mx){
                        mx = r-l+1;
                        ans = s.substr(l, mx);
                    }
                }
                else break;
                l--;
                r++;
            }
        }
        return ans;
    }
};