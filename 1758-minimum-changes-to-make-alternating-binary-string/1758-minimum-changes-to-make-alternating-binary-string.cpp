class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), ct = 0;
        int f = 0;
        for(int i = 0; i < n; i++){
            if(s[i]-'0' == f) ct++;
            f = 1-f;
        }
        return min(ct, n-ct);
    }
};