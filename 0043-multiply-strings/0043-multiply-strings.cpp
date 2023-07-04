class Solution {
public:
    string multiply(string n1, string n2) {
        int n = n1.length(), m = n2.length();
        string ans(n+m, '0');
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int sum = (n1[i]-'0')*(n2[j]-'0') + (ans[i+j+1]-'0');
                ans[i+j+1] = sum%10 + '0';
                ans[i+j] += sum/10;
            }
        }
        
        for(int i = 0; i < n+m; i++){
            if(ans[i] != '0') return ans.substr(i);
        }
        return "0";
    }
};