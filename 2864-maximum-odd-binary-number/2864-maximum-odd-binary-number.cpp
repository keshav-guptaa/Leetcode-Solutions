class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string ans;
        int x = count(s.begin(), s.end(), '1');
        for(int i = 0; i < n; i++){
            if(i < x-1) ans += '1';
            else ans += '0';
        }
        ans[n-1] = '1';
        return ans;
    }
};