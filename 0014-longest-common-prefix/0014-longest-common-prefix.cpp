class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(n == 1) return s[0];
        string ans = "";
        for(int i = 0; i < s[0].length() && i < s[1].length(); i++){
            if(s[0][i] == s[1][i]) ans += s[1][i];
            else break;
        }
        for(int i = 2; i < n; i++){
            string temp = "";
            for(int j = 0; j < s[i].length() && j < ans.length(); j++){
                if(s[i][j] == ans[j]) temp += ans[j];
                else break;
            }
            ans = temp;
        }
        return ans;
    }
};