class Solution {
public:
    string solve(int n){
        if(n==1){
            return "1";
        }
        string s= solve(n-1);
        int count=1,i=1;
        char ch = s[0];
        string ans="";
        while(i < s.length()){
            if(s[i] == ch){
                count++;
            }
            else{
                ans += to_string(count);
                count = 1;
                ans += ch;
                ch = s[i];
            }
            i++;
        }
        ans += to_string(count);
        ans += ch;
        return ans;
    }
    string countAndSay(int n) {
        string res= solve(n);
        return res;
    }
};