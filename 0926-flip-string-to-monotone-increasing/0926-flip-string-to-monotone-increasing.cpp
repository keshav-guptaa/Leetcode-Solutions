class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zero = count(s.begin(), s.end(), '0');
        int one = count(s.begin(), s.end(), '1');
        int ans = zero, ct0 = 0, ct1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') ct0++;
            else ct1++;
            ans = min(ans, ct1 + (zero-ct0));
        }
        return ans;
    }
};