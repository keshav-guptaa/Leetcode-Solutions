typedef long long ll;
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int pos = -1, mod = 1e9+9, p = 31;
        ll ph = 0, sh = 0, power = 1;
        for(int i = 0; i < n; i++){
            ph = (ph + (s[i]-'a'+1)*power)%mod;
            power = (power*p)%mod;
            sh = (sh*p + (s[i]-'a'+1))%mod;
            if(ph == sh) pos = i;
        }
        string extra = s.substr(pos+1);
        reverse(extra.begin(), extra.end());
        return extra + s;
    }
};