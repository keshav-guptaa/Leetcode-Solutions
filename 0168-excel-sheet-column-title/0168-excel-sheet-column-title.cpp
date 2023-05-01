class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        char ch;
        while(n){
            n--;
            ch = 'A' + n%26;
            ans = ch + ans;
            n /= 26;
        }
        return ans;
    }
};