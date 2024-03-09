class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "", temp = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] != ' ') temp += s[i];
            else{
                if(temp.length() != 0){
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                }
                temp = "";
                if(ans.length() != 0 && ans[ans.length()-1] != ' ') ans += s[i];
            }
        }
        if(temp.length() != 0){
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        n = ans.length();
        for(int i = n-1; i >= 0; i--){
            if(ans[i] == ' ') ans.pop_back();
            else break;
        }
        return ans;
    }
};