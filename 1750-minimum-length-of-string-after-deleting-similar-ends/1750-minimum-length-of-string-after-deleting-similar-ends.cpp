class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), i = 0, j = n-1, ans = n;
        while(i < j){
            int ct = 0;
            while(i+1 < j && s[i] == s[i+1]){
                i++;
                ct++;
            }
            while(j-1 > i && s[j] == s[j-1]){
                j--;
                ct++;
            }
            if(s[i] == s[j]){
                ct += 2;
                ans -= ct;
                i++; j--;
            }
            else break;
        }
        return ans;
    }
};