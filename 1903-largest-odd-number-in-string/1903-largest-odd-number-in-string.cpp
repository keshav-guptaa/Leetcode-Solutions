class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1;
        for(int i = 0; i < num.length(); i++){
            if((num[i]-'0')&1) idx = i;
        }
        string ans = "";
        for(int i = 0; i <= idx; i++) ans += num[i];
        return ans;
    }
};