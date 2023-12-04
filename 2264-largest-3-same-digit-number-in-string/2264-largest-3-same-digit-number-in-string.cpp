class Solution {
public:
    string largestGoodInteger(string num) {
        int idx = -1, n = num.length();
        for(int i = 0; i < n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]) idx = max(idx, num[i]-'0');
        }
        string ans = "";
        if(idx != -1){
            for(int i = 0; i < 3; i++) ans += '0'+idx;
        } 
        return ans;
    }
};