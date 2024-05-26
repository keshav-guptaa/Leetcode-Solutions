class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.length();
        int ct = 1;
        for(int i = 1; i < n; i++){
            if(word[i] != word[i-1]){
                char ch = '0' + ct;
                ans += ch;
                ans += word[i-1];
                ct = 1;
            }
            else{
                if(ct == 9){
                    ans += '9';
                    ans += word[i-1];
                    ct = 1;
                }
                else ct++;
            }
        }
        char ch = '0' + ct;
        ans += ch;
        ans += word[n-1];
        return ans;
    }
};